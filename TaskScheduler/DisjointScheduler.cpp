/*
DisjointScheduler.hpp
Implementation file
*/
#include "DisjointScheduler.hpp"
#include "MembershipTree.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

//constructor.  creates membership tree with maxTime+1
DisjointScheduler::DisjointScheduler(int t) : membershipTree(t+1){		//initialize memberShip tree with t+1 to match schedule
	this->maxTime = t;
	schedule.resize(maxTime+1);
	for(int i =0; i<schedule.size(); i++){			//nothing scheduled when first contructed
		schedule[i] = NULL;
	}	
}

//addTask()
void DisjointScheduler::addTask(string id, int theDeadline, int theProfit){
	node* newNode = new node;
	newNode->ID = id;
	newNode->deadline = theDeadline;
	newNode->profit = theProfit;
	tasks.push_back(newNode);
}

//sheduleTasks()
void DisjointScheduler::scheduleTasks(){
	
	for(int i=0; i < tasks.size(); i++){
		if(tasks[i]->deadline <= maxTime){
			int timeSlot = membershipTree.findSet(tasks[i]->deadline);		//check for open time slot in membershipTree using deadline of task
			if(timeSlot!=0 && schedule[timeSlot]==NULL){
				schedule[timeSlot]= tasks[i];					//schedule task at timeslot
				membershipTree.merge(timeSlot,timeSlot-1);			//merge timeSlot with next open timeSlot. will be 0 if no more times available	
			}
		}
	}
		
}

//sortTasks()   sorts tasks based on profit
void DisjointScheduler::sortTasks(){
	sort(tasks.begin(),tasks.end(), sortByProfit);
}

//sortByProfit()
bool DisjointScheduler::sortByProfit(node* a, node* b){
	return (a->profit > b->profit);
}

void DisjointScheduler::printSchedule(){
	int sum=0;
	for(int i=0; i<schedule.size(); i++){
		if(schedule[i]!=NULL){
	//		cout << schedule[i]->ID << endl;
			sum+= schedule[i]->profit;
		}else if(i!=0){
	//		cout << "(empty)" << endl;
		}
	}
	cout <<  sum <<endl;
}	
