
Graph::Graph(bool insertReverseEdge, ifstream& ifs) {
	
	// get each line
	// each line will be 3 characters
	// 1st char will be the key and the 3rd character will be the data
	// https://stackoverflow.com/questions/7868936/read-file-line-by-line
	int a, b;
	while (ifs >> a >> b) {
		vertex_list[a]->edge_list.push_back(new Edge{b, 0});
		vertex_list[a]->vertex_id = a;
		vertex_list[a]->data->visited = false;
		
		num_edges++;
	}
}

Graph::~Graph {
	
}

void Graph::printGraph() {
	for (auto v : vertex_list) {
		for (auto e : v) {
			cout << v->vertex_id << ' ' << e << endl;
		}
	}
}

void Graph::BFS(int vs) {
	
}

void Graph::DFS(int vs) {
	
}