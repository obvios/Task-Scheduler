/*
NaiveScheduler.cpp
Implementation file
*/

#include "NaiveScheduler.hpp"
#include <vector>
#include <algorithm>
using namespace std;

//constructor
NaiveScheduler::NaiveScheduler(int size,int t){
	this->n = size;
	this->maxTime = t;
//	tasks.resize(n);
	schedule.resize(maxTime+1);
	for(int i=0; i<schedule.size(); i++){
		schedule[i]=NULL;
	}	
}

//addTask()
void NaiveScheduler::addTask(string id, int theDeadline, int theProfit){
	node* newNode = new node;
	newNode->ID = id;
	newNode->deadline = theDeadline;
	newNode->profit = theProfit;
	tasks.push_back(newNode);
}

//scheduleTasks
void NaiveScheduler::scheduleTasks(){
	for(int i =0; i <tasks.size(); i++){
	   if(tasks[i]->deadline<=maxTime){
		for(int d= tasks[i]->deadline; d>=1 ;d--){			//start at the deadline and find an open spot
			if(schedule[d]==NULL){					//the time slot is open
				schedule[d] = tasks[i];			//point the time slot to the specified task
				break;	
			}

		}	
	   }
	}
}

//sortTasks()   sorts tasks based on profit
void NaiveScheduler::sortTasks(){
	sort(tasks.begin(),tasks.end(), sortByProfit);
}

//sortByProfit()
bool NaiveScheduler::sortByProfit(node* a, node* b){
	return (a->profit > b->profit);
}

//printSchedule
void NaiveScheduler::printSchedule(){
	int sum=0;
	for(int i=0; i<schedule.size(); i++){
		if(schedule[i]!=NULL){
		//	cout << schedule[i]->ID << endl;
			sum+= schedule[i]->profit;
		}else if(i!=0){
		//	cout << "(empty)" << endl;
		}
	}
	cout <<  sum <<endl;
}	
