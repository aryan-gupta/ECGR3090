#include "graph.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using clk = std::chrono::steady_clock;

int main()
{
    ifstream ifs("facebook_combined.txt");
    //ifstream ifs("sample_edges.txt");
	Graph fb{false, ifs};
	
	auto start = clk::now();
	fb.getNewFriends(0);
	auto end = clk::now();
	
	auto time = duration_cast<milliseconds>(end - start).count();
	
	cout << "Time it took was " << time << " ms" << endl;
	
	fb.getBestFriends(124);
	
    return 0;
}