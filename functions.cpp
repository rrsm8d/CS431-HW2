#include "functions.h"

vector<Process> CreateProcesses(int& pCount)
{
	int qTime, burst, priority, arrivalTime;
	vector<Process> processList;
	for (int i = 0; i < pCount; i++)
	{
		cout << "Enter p" << i+1 << " burst time: "; cin >> burst;
		cout << "Enter p" << i+1 << " priority: "; cin >> priority; // Irrelevant to SJF, included anyways
		cout << "Enter p" << i+1 << " arrival time: "; cin >> arrivalTime;
		Process newProcess = { i+1, burst, priority, arrivalTime };
		processList.push_back(newProcess);
		cout << endl << endl;
	}
	return processList;
}

void SJF(vector<Process>& waitingProcesses)
{
	vector<Process> runningProcesses;
	int currentTime = 0;
	double waitingTime = 0.0;
	int pCount = waitingProcesses.size();

	// WHile there are still processes to run
	while (runningProcesses.size() > 0 || waitingProcesses.size() > 0)
	{
		// If any processes are ready to be ran, prepare to run them
		for (int i = 0; i < waitingProcesses.size(); i++)
		{
			if (waitingProcesses[i].arrivalTime <= currentTime)
			{
				runningProcesses.push_back(waitingProcesses[i]);
				waitingProcesses.erase(waitingProcesses.begin() + i);
				i--;
			}
		}

		int shortestIndex = 0;
		int shortestBurst = 9999999;
		// Pick the shortest process to run
		for (int i = 0; i < runningProcesses.size(); i++)
		{
			if (runningProcesses[i].burstTime < shortestBurst)
				{
				shortestIndex = i;
				shortestBurst = runningProcesses[i].burstTime;
			}
		}
		// Advance time by how long the process was run for
		currentTime += shortestBurst;
		// Calculate waiting time for this individual process
		waitingTime += (currentTime - (runningProcesses[shortestIndex].arrivalTime + runningProcesses[shortestIndex].burstTime));

		cout << "p" << runningProcesses[shortestIndex].id << " was run for " << shortestBurst <<  endl;
		runningProcesses.erase(runningProcesses.begin() + shortestIndex);
	}
	cout << endl << "Total runtime: " << currentTime << endl;
	cout << "Average waiting time: " << waitingTime/static_cast<double>(pCount) << endl;
}

