/*
MembershipTree.hpp
header file
*/
#ifndef MembershipTree_hpp
#define MembershipTree_hpp
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class MembershipTree{
private:
	struct node{
		int ID;	
		node* parent;
	};
   	map<int,node*> tasksMap;    //holds the tasks
	node* findSet(node*);
public:
	MembershipTree(int);
   	int findSet(int id);
	void merge(int,int);
};

#endif /*MembershipTree_hpp*/
