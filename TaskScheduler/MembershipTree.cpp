/*
MembershipTree.cpp
Implementation file
*/

#include "MembershipTree.hpp"
#include <iostream>
#include <vector>
using namespace std;

//constructor
MembershipTree::MembershipTree(int n){				//n represents the total amnt of set. Equal to max time to complete tasks
    node* nullNode = new node;
    nullNode->ID=0;
    nullNode->parent = nullNode;
    tasksMap.emplace(nullNode->ID,nullNode);
	for(int i=1; i < n;i++){
		node* newNode = new node;
		newNode->parent = newNode;                      //initialize all sets to point to themselves
		newNode->ID = i;
        	tasksMap.emplace(newNode->ID,newNode);          //store our set
	}	
}

//public findSet
int MembershipTree::findSet(int id){
	return findSet(tasksMap.at(id))->ID;
}

//private findSet
MembershipTree::node* MembershipTree::findSet(node* theNode){
    if(theNode->parent == theNode){
		return theNode;
	}
	theNode->parent = findSet(theNode->parent);
	return theNode->parent;
}

//merge()
void MembershipTree::merge(int curSet, int newSet){
    node* curNode = tasksMap.at(curSet);
    node* newNode  = tasksMap.at(newSet);

	node* oldParent = findSet(curNode);
	node* newParent = findSet(newNode);

	if(oldParent == newParent){			//if both tasks are in same tree do nothing
		return;
	}
	oldParent->parent = newParent;
}
