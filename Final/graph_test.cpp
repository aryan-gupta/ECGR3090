#include "graph.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using clk = std::chrono::steady_clock;

int main()
{
	cout << "Welcome to the friend database" << endl;
	auto start = clk::now();
    ifstream ifs("facebook_combined.txt");
    //ifstream ifs("sample_edges.txt");
	Graph fb{false, ifs};
	auto end = clk::now();
	auto time = duration_cast<milliseconds>(end - start).count();
	
	cout << "Time that it took to create the database was " << time << " ms" << endl;
	cout << "There are " << fb.getNumVertices() << " friends in the database" << endl;
	cout << endl;
	
	while (true) {
		cout << "Please select an operation" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Get best friends" << endl;
		cout << "2) Find new friends" << endl;
		cout << ":: ";
		int option{};
		cin >> option;
		
		if (option == 0) break;
		
		switch (option) {			
			case 1: {
				cout << "Select a friend to find best friends for" << endl;
				cout << ":: ";
				
				int vertex;
				cin >> vertex;
				
				start = clk::now();
				auto results = fb.getBestFriends(vertex);
				end = clk::now();
				
				time = duration_cast<milliseconds>(end - start).count();
				
				cout << "It took " << time << " ms to find all the best friends" << endl;
				
				cout << "Select the max number of best friends you want to display" << endl;
				cout << ":: ";
				int amount;
				cin >> amount;
				
				amount = (amount > results.size())? results.size() : amount;
				
				cout << "The top " << amount << ((amount > 1)? " best friends are" : " best friend is") << endl;
				for (int i = 0; i < amount; ++i) {
					cout << results[i].first << endl;
				}
				
				cout << endl << endl;
				
			} break;
			
			case 2: {
				cout << "Select a friend to find potential new friends for" << endl;
				cout << ":: ";
				
				int vertex;
				cin >> vertex;
				
				start = clk::now();
				auto results = fb.getNewFriends(vertex);
				end = clk::now();
				
				time = duration_cast<milliseconds>(end - start).count();
				
				cout << "It took " << time << " ms to find all the potential new friends" << endl;
				
				cout << "Select the max number of best friends you want to display" << endl;
				cout << ":: ";
				
				int amount;
				cin >> amount;
				
				amount = (amount > results.size())? results.size() : amount;
				
				cout << "The top " << amount << " new potential" << ((amount > 1)? " friends are" : " friend is") << endl;
				for (int i = 0; i < amount; ++i) {
					cout << results[i].first << endl;
				}
				
				cout << endl << endl;				
			} break;
			
			default:
				cerr << "A wrong option was chosen, Please try again" << endl;
		}
	
	}	
    return 0;
}