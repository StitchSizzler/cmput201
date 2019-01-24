/* Johnson's rule */


#include "mp.h"

// machines B and C
#define MAC 2

int johnson(Jobs *jobs, int len, int num_machines, int t){

	// struct to store job_number, time_b, time_c, time_min, min_mac
	typedef struct  {
		int job_number;
		int time_b;
		int time_c; 
		int time_min; /* min{time_b, time_c} */
		int min_mac; /* 0 for B, 1 for c */
	} Temp;




	// sort jobs according to time
	// in ascending order
	// take min of time_b and time_c

	Temp temp_jobs[len];
	for (int i  = 0; i < len; i++){

		temp_jobs[i].job_number = jobs[i].job_number;
		temp_jobs[i].time_b = jobs[i].time_b;
		temp_jobs[i].time_c = jobs[i].time_c;

		int t_min = jobs[i].time_b;
		temp_jobs[i].time_min = t_min;
		temp_jobs[i].min_mac = 0;
		if (jobs[i].time_c < t_min){
			t_min = jobs[i].time_c;
			temp_jobs[i].time_min = t_min;
			temp_jobs[i].min_mac = 1;
		}

	}




	// bubble sort
	for (int i = 0; i < len-1 ; i++){
		
		for (int j = 0; j < len-i-1; j++){
			
			if(temp_jobs[j].time_min > temp_jobs[j+1].time_min){
				Temp temp = temp_jobs[j];
				temp_jobs[j] = temp_jobs[j+1];
				temp_jobs[j+1] = temp;	
			}		
		}		
	}

	// store jobs according to time_b or time_c
	// time_b goes first and time_c goes last
	Temp job_order[len];
	int first = 0;
	int last = len-1;
	for (int i = 0; i < len; i++){
		// check if min is time_b
		if(temp_jobs[i].min_mac == 0){
			job_order[first++] = temp_jobs[i];
		}
		// min is time_c
		else{
			job_order[last--] = temp_jobs[i];
		}
	}


	// decide times for machine B and C
	// struct to store machine# and start time 
	typedef struct  {
		int job_number;
		int time_start;
		int time_end;
	} Times;

	Times b_times[len], c_times[len];

	// store times for B 
	// simple increment the time
	int b_t = t;
	for (int i = 0; i < len; i++){
		b_times[i].job_number = job_order[i].job_number;
		b_times[i].time_start = b_t;
		b_t += job_order[i].time_b;
		b_times[i].time_end = b_t;
	}

	// store times for C
	// start time is max{prev c finish, current b finish}
	int c_t = b_times[0].time_end;
	for (int i = 0; i < len; i++){
		c_times[i].job_number = job_order[i].job_number;
		if (b_times[i].time_end > c_t){
			c_t = b_times[i].time_end;
		}
		c_times[i].time_start = c_t;
		c_t += job_order[i].time_c;
		c_times[i].time_end = c_t;
	}


	int t_end = c_times[len-1].time_end;
	int makespan = t_end - t;

	return makespan;
}
