/*
NaiveScheduler.hpp
header file
*/
#ifndef NaiveScheduler_hpp
#define NaiveScheduler_hpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NaiveScheduler{
	struct node{
		string ID;
		int deadline;
		int profit;
	};
	int n;
	int maxTime;
	vector<node*>tasks;
	vector<node*>schedule;		//holds the tasks in scheduled form	
public:
	NaiveScheduler(int size,int t);
	void addTask(string, int, int);
	void scheduleTasks();
	void sortTasks();
	static bool sortByProfit(node* a, node* b);
	void printSchedule();		//for testing
};
#endif /*NaiveScheduler.hpp*/
