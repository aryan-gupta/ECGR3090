#include "graph.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs("sample_edges.txt");
    Graph g(false, ifs);
    cout << "Number of vertices " << g.getNumVertices() << endl;
    cout << "Number of edges " << g.getNumEdges() << endl;
    cout << "Printing graph" << endl;
    g.printGraph();
    cout << "Printing vertices in BFS order starting at vertex 0 " << endl;
    g.BFS(0);
    cout << "Printing vertices in DFS order starting at vertex 0 " << endl;
    g.DFS(0);
    return 0;
}