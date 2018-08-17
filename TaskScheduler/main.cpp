//
//  main.cpp
//  Assignment5
//
//  Created by Eric Palma on 4/26/18.
//  Copyright © 2018 Eric Palma. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "NaiveScheduler.hpp"
#include "DisjointScheduler.hpp"
using namespace std;
void createVector(string,vector<int>&);
void createStringVector(string, vector<string>&);
int generateNumBetween(int, int);

int main(int argc, const char * argv[]) {
    char Y_N;
    int optionChoice;
    srand(time(0));
    
    /*cout << "Which option? ";
    cin >> optionChoice;*/
    
    do{                                 //start do while loop
        cout << "Which option? ";
        cin >> optionChoice;
    if(optionChoice==1){
    	string fileName;
    	ifstream textFile;
	int maxT;			//maximum time to complete tasks
	cout << "Enter file name: ";
	cin >> fileName;	
	cout << "Enter max T: ";
	cin >> maxT;
    	textFile.open(fileName);
    	vector<string> row1;
    	vector<int> row2;
    	vector<int> row3;
   	 
    	if (textFile.is_open()) {
        	while (!textFile.eof()) {
                string firstRow, secondRow, thirdRow;
                getline(textFile, firstRow);
                getline(textFile, secondRow);
                getline(textFile, thirdRow);
                createStringVector(firstRow, row1);           //this is going to be a string
                createVector(secondRow, row2);
                createVector(thirdRow, row3);
        	}
        	textFile.close();
    	}
 	NaiveScheduler taskScheduler(row1.size(),maxT);	
	for(int i=0; i<row1.size(); i++){		     //add tasks
		taskScheduler.addTask(row1[i],row2[i],row3[i]);	
	}
	taskScheduler.sortTasks();				//sort tasks by profit	
   	taskScheduler.scheduleTasks();
	cout << "Naive implementation: ";
	taskScheduler.printSchedule();

	//use DisjointScheduler
	row1.clear();					//reset vectors
	row2.clear();
	row3.clear();
	textFile.open(fileName);
    	if (textFile.is_open()) {
        	while (!textFile.eof()) {
                string firstRow, secondRow, thirdRow;
                getline(textFile, firstRow);
                getline(textFile, secondRow);
                getline(textFile, thirdRow);
                createStringVector(firstRow, row1);           //this is going to be a string
                createVector(secondRow, row2);
                createVector(thirdRow, row3);
        	}
        	textFile.close();
    	}
	DisjointScheduler disjointTaskScheduler(maxT);
	for(int i=0; i<row1.size(); i++){		     //add tasks
		disjointTaskScheduler.addTask(row1[i],row2[i],row3[i]);	
	}
	disjointTaskScheduler.sortTasks();				//sort tasks by profit	
   	disjointTaskScheduler.scheduleTasks();
	cout << "Disjoint implementation: ";
	disjointTaskScheduler.printSchedule();

    }
    
    if(optionChoice==2){
	int n,a,b,p,q,maxT;
	cout << "Enter n, a , b, p, q: ";
	cin >> n >> a >> b >> p >> q;
	cout << "Enter max time: ";
	cin >> maxT;	
	vector<int>id;
	vector<int>deadlines;
	vector<int>profits;
	
        NaiveScheduler naiveScheduler(n,maxT);
	DisjointScheduler disjointScheduler(maxT);
	
	for(int i = 1; i <=n; i++){				//create n elements and add them to naive scheduler
		id.push_back(i);
		deadlines.push_back(generateNumBetween(a, b));
		profits.push_back(generateNumBetween(p, q));
	} 	
	
	for(int i=0; i<id.size(); i++){				//add tasks to schedulers
	        naiveScheduler.addTask(to_string(id[i]), deadlines[i], profits[i]);
        	disjointScheduler.addTask(to_string(id[i]), deadlines[i], profits[i]);
	}
	
        chrono::steady_clock::time_point elapsedTimeBegin = chrono::steady_clock::now();
	naiveScheduler.sortTasks();				//use naive scheduler first. Time and print elapsed time along with profit;
	naiveScheduler.scheduleTasks();
        naiveScheduler.printSchedule();
        chrono::steady_clock::time_point elapsedTimeEnd = chrono::steady_clock::now();
        cout << "Elapsed time naive: " << chrono::duration_cast<chrono::seconds>(elapsedTimeEnd-elapsedTimeBegin).count() << " seconds";

	cout << endl;

	elapsedTimeBegin = chrono::steady_clock::now();
	disjointScheduler.sortTasks();				//use disjoint scheduler. Time and print elapsed time along with profit
	disjointScheduler.scheduleTasks();
	naiveScheduler.printSchedule();
	elapsedTimeEnd = chrono::steady_clock::now();
	cout << "Elapsed time disjoint: " << chrono::duration_cast<chrono::milliseconds>(elapsedTimeEnd-elapsedTimeBegin).count() << " ms";
	cout << endl;
    }
        cout << "would you like to continue? ";
        cin >> Y_N;
    } while(toupper(Y_N)=='Y');                                     //end do-while loop
    return 0;
}



/********************************
 *       createVector()         *
 * creates vector from values   *
 *******************************/
void createVector(string line, vector<int>& theVector){
    for (int i=0; i<line.length(); i++) {
        string value="";
        while (line[i]!=','&& i<line.length()) {
            value+=line[i];
            i++;
        }
        theVector.push_back(stoi(value));
    }
}


void createStringVector(string line, vector<string>& theVector){
    for (int i=0; i<line.length(); i++) {
        string value="";
        while (line[i]!=',' && i<line.length()) {
            value+=line[i];
            i++;
        }
        theVector.push_back(value);
    }
}

/*********************************
*	generateNumBetween()	 *
*********************************/
int generateNumBetween(int start, int finish){
	//return ((rand() % finish) + start);
    int num;
    num = start + (rand()  % (finish - start + 1));
    return num;
}
