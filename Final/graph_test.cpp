#include "graph.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs("facebook_combined.txt");
    //ifstream ifs("sample_edges.txt");
	Graph fb{false, ifs};
	
	fb.getNewFriends(0);
	
    return 0;
}