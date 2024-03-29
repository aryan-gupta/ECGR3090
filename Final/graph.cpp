
#include <iostream>
#include <queue>
#include <functional>
#include <unordered_map>
#include <algorithm>
using namespace std;

#include "graph.h"

Graph::Graph(bool insertReverseEdge, ifstream& ifs) 
: vertex_list{}, num_edges{} {
	
	// get each line
	// each line will be 3 characters
	// 1st char will be the key and the 3rd character will be the data
	// https://stackoverflow.com/questions/7868936/read-file-line-by-line
	int a, b;
	while (ifs >> a >> b) {		
		if (vertex_list.find(a) == vertex_list.end()) {
			vertex_list[a] = new Vertex{a, new Data{false}, vector<Edge*>()};
		}
		
		if (vertex_list.find(b) == vertex_list.end()) {
			vertex_list[b] = new Vertex{b, new Data{false}, vector<Edge*>()};
		}
		
		vertex_list[a]->edge_list.push_back(new Edge{b, 0});		
		num_edges++;
	}
}

Graph::~Graph() {
	for (auto p : vertex_list) {
		for (auto e : p.second->edge_list) {
			delete e;
		}
		
		delete p.second->data;
	}
}

void Graph::printGraph() {	
	for (int i = 0; i < getNumVertices(); ++i) {
		for (auto e : vertex_list[i]->edge_list) {
			cout << i << ' ' << e->target_vertex << endl;
		}
	}
}

void Graph::BFS(int vs) {
	std::queue<int> vertices;
	
	vertices.push(vs);
	vertex_list[vs]->data->visited = true; // push and set first vertex to visited
	
	while (!vertices.empty()) {
		int v = vertices.front();		
		vertices.pop();
		
		cout << v << ' ';
		
		for (auto e : vertex_list[v]->edge_list) {
			if (vertex_list[e->target_vertex]->data->visited == false) {
				vertices.push(e->target_vertex);
				vertex_list[e->target_vertex]->data->visited = true;
			}
		}
	}
	
	cout << endl;
	
	for (auto v : vertex_list) {
		v.second->data->visited = false;
	}
}

void Graph::DFS(int vs) {
	std::function<void(int vs)> dfs_recurse = [&](int vs){
		
		cout << vs << ' ';
		vertex_list[vs]->data->visited = true;
		
		for (auto e : vertex_list[vs]->edge_list)
			if (vertex_list[e->target_vertex]->data->visited == false)
				dfs_recurse(e->target_vertex);
	};
	
	dfs_recurse(vs);
	
	for (auto v : vertex_list) {
		v.second->data->visited = false;
	}
}


std::vector<std::pair<int, double>> Graph::getNewFriends(int vs) {
	std::unordered_map<int, double> friends;
	
	/// @todo make this recursive
	for (auto e1 : vertex_list[vs]->edge_list) { // this is level 1 (already our friend))
		for (auto e2 : vertex_list[e1->target_vertex]->edge_list) { // this is level 2 (potential friends)
			friends[e2->target_vertex] += 0.5;
			
			for (auto e3 : vertex_list[e2->target_vertex]->edge_list) {
				friends[e3->target_vertex] += 1/9.0;
				
				for (auto e4 : vertex_list[e3->target_vertex]->edge_list) {
					friends[e4->target_vertex] += 1/16.0;
				}
			}
		}
	}
	
	std::vector<std::pair<int, double>> tmp{friends.begin(), friends.end()};
	std::sort(tmp.begin(), tmp.end(), [](auto a, auto b) {return a.second > b.second;});

	return tmp;
}


std::vector<std::pair<int, double>> Graph::getBestFriends(int vs) {
	std::unordered_map<int, double> bestfriends;
	
	for (auto e : vertex_list[vs]->edge_list) {
		for (auto ef : vertex_list[e->target_vertex]->edge_list) {
			if (ef->target_vertex == vs)
				bestfriends[e->target_vertex] += 5;
		}
	}
	
	for (auto eo : vertex_list[vs]->edge_list) { // level 1 (already friends)
		for (auto ef : vertex_list[eo->target_vertex]->edge_list) { // level 2 (friend of friend)
			for (auto efof : vertex_list[ef->target_vertex]->edge_list) { // level 3
				if (efof->target_vertex == vs)
					bestfriends[eo->target_vertex] += 1;
			}
		}
	}
	
	for (auto eo : vertex_list[vs]->edge_list) { // level 1 (already friends)
		for (auto ef : vertex_list[eo->target_vertex]->edge_list) { // level 2 (friend of friend)
			for (auto e : vertex_list[vs]->edge_list) { // level 3
				if (e->target_vertex == ef->target_vertex) {
					bestfriends[eo->target_vertex] += 1;
					bestfriends[e->target_vertex] += 1;
				}
			}
		}
	}
	
	std::vector<std::pair<int, double>> tmp{bestfriends.begin(), bestfriends.end()};
	std::sort(tmp.begin(), tmp.end(), [](auto a, auto b) {return a.second > b.second;});

	return tmp;
}