#include "functions.h"
 
// 5 2 2 0 1 1 1 8 4 2 4 2 3 5 3 4 
// Input from assignment. copy and pasting will ruin the output format however

int main() {
	int pCount = 0;
	cout << "Enter # of processes to be scheduled: "; cin >> pCount;
	vector<Process> processList = CreateProcesses(pCount);
	SJF(processList);
	return 0;
}
