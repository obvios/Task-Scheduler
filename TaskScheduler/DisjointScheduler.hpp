/*
DisjointScheduler.hpp
Header file
*/

#ifndef DisjointScheduler_hpp
#define DisjointScheduler_hpp
#include <iostream>
#include <vector>
#include "MembershipTree.hpp"
using namespace std;

class DisjointScheduler{
	struct node{
		string ID;
		int deadline;
		int profit;
	};
	vector<node*>tasks;			//holds tasks
	int maxTime;				//max time to complete tasks
	vector<node*>schedule;			//holds tasks in scheduled form
	MembershipTree membershipTree;		//membership tree for this list of tasks
public:
	DisjointScheduler(int);
	void addTask(string, int, int);
	void scheduleTasks();
	void sortTasks();
	static bool sortByProfit(node* a, node* b);
	void printSchedule();		//for testing
};

#endif /*DisjointScheduler_hpp*/
