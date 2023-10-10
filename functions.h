#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Process {
	int id = 0;
	int burstTime = 0;
	int priority = 0;
	int arrivalTime = 0;

};

// Pre: Int for number of processes to be made
// Post: Create a process vector and returns it
vector<Process> CreateProcesses(int& pCount);

// Pre: Vector of processes filled by CreateProcesses
// Post: Prints the order of processes ran, avg waiting time, and total time
void SJF(vector<Process>& processes);

