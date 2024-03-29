
#include <iostream>
#include <queue>
#include <functional>
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
	
}

void Graph::printGraph() {
	// for (auto v : vertex_list) {
		// for (auto e : v.second->edge_list) {
			// cout << v.second->vertex_id << ' ' << e->target_vertex << endl;
		// }
	// }
	
	// cout << endl;
	
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