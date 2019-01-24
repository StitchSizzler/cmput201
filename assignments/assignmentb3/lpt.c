#include "mp.h"

int find_machine(int mac_times[], int num_machines);

int lpt(Jobs *jobs, int len, int num_machines, int t){

	
	// struct to store machine# and start time 
	typedef struct  {
		int machine_number;
		int time_start;
	} Times;

	Times times[len];

	// array to store machine times
	int mac_times[num_machines];
	// initilize times with t
	for (int i = 0; i < num_machines; i++){
		mac_times[i] = t;
	}

	// store times and machines in struct array
	int key;
	for (int i = 0; i < len; i++){
		key = find_machine(mac_times, num_machines);
		times[i].machine_number = key+1;
		times[i].time_start = mac_times[key];
		mac_times[key] = mac_times[key] + jobs[i].time_a;
	}

	int largest = 0;
	for (int i = 0; i < num_machines; i++){
		if (mac_times[i] > largest)
			largest = mac_times[i];
	}
	int makespan = largest - t;

	return makespan;
}


int find_machine(int mac_times[], int num_machines){

	// find machine with smallest time
	
	int key = 0;
	for (int i = 0; i < num_machines; i++){
		if (mac_times[i] < mac_times[key])
			key = i;
	}
	return key;
}

