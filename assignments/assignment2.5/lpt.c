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

	

  // print Job Information
  printf("\nJob information:\n");
  for (int i = 0; i < len; i++){
	printf("Job %d is processed on A_%d starting %d;\n", jobs[i].job_number, times[i].machine_number, times[i].time_start);
  }
  printf("\n");

  // print Machine Information
  int mac_num;
  printf("Machine information:");
  for (int i = 0; i < num_machines; i++){
	mac_num = i+1;
	printf("\nA_%d processes", mac_num);
	for (int j = 0; j < len; j++){
		if (times[j].machine_number == mac_num){
			printf(" job %d at %d,", jobs[j].job_number, times[j].time_start);
		}
	}
  }
  printf("\n");

	//int t_end = times[0].time_start + jobs[0].time_a;
	int largest = 0;
	for (int i = 0; i < num_machines; i++){
		if (mac_times[i] > largest)
			largest = mac_times[i];
	}
	//t_end = times[0]. 
	int makespan = largest - t;
	printf("\nThe job processing time interval is [%d, %d], and the makespan is %d\n", t, largest, makespan);

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





/*
  for (int i = 0; i < len; i++){
	printf("%d ", jobs[i].job_number);
  }
  printf("\n");
*/
/*
    int to_sort[num_jobs];
    // copy array into another
    for (int i = 0; i < num_jobs; i++)
        to_sort[i] = set_jobs[i];  

    // insertion sort
    for (int i = 1; i < num_jobs; i++){
        int key = to_sort[i];
        int k = i - 1;
        while (k >= 0 && to_sort[k] > key){
            to_sort[k + 1] = to_sort[k];
            k--;
        }
        to_sort[k + 1] = key;
    }


    int count = 0;
    int exist = 0;
    int index;

    // get num_mac largest elements
    for (int i = num_jobs-1; i >= num_jobs-num_mac; i--){ 
        
        // iterate through to_sort to find index
        for (int j = 0; j < num_jobs; j++){

            if (set_jobs[j] == to_sort[i]){
                index = j;

                // check if index exist in j1
                exist = 0;
                for (int k = 0; k < count; k++){

                    if (j1[k] == index+1){
                        exist = 1;
                        break;
                    }
                }

                if (exist == 0){
                    j1[count++] = index+1;
                }
            }
        }

    } 

    // print lpt
    printf("\nLPT order: ");
    for (int num = 0; num < num_mac; num++){
        printf("%d", j1[num]);
        if (num < num_mac-1)
            printf(", ");
    }

    // print job information
    printf("\nJob information:\n");

    // array to store current times. Start at t each
    int a_times[num_mac];
    for (int k = 0; k < num_mac; k++)
        a_times[k] = t;
        
        // find min time
        int min = t;
        int busy_mac = 1;
        int busy_time;
        int curr_time;
        int curr_index;
        int job = 0;

    // assign times, iterate through num machines 
    for (int mac = 0; mac < num_mac; mac++){

        for (int i = 0; i < num_mac; i++){
            job = j1[i] - 1;
            if ((min >= a_times[i]) || a_times[i] == 0){
                //printf("min: %d  ", min);
                //printf("a_times[i]: %d\n", a_times[i]);
                min = a_times[i];
                busy_mac = i; 
            }

        }


        printf("Job %d is processed on A_%d starting %d", j1[mac], busy_mac+1, a_times[busy_mac]);
        busy_time = a_times[busy_mac];
        curr_index = j1[mac];
        curr_time = set_jobs[curr_index];
        busy_time += curr_time;
        a_times[busy_mac] = busy_time;
        
        if (mac < num_mac-1)
            printf(";\n");
        else
            printf(".\n");
    }

    // print machine information
    printf("\nMachine information:\n");
    for (int mac = 0; mac < num_mac; mac++){
        printf("A_%d processes job %d at %d", mac+1, j1[mac], t);
        if (mac < num_mac-1)
            printf(";\n");
        else
            printf(".\n");
    }
 
    int makespan = set_jobs[j1[0]-1]-t;
    printf("The job processing time interval is [%d, %d] and the makespan time is %d.\n", 
        t, set_jobs[j1[0]-1], makespan);

    return makespan;   
*/


