#include "graph.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs("facebook_combined.txt");
	Graph fb{false, ifs};
	
	fb.getNewFriends(5);
	
    return 0;
}