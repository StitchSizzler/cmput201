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

	// print Job Information
	printf("\nJob information:\n");
	for (int i = 0; i < len; i++){
		printf("Job %d is processed on B starting %d, on C starting %d;\n", job_order[i].job_number, b_times[i].time_start, c_times[i].time_start);
	}
	printf("\n");


	// print Machine Information
	printf("Machine information");

	// print mac B
	printf("\nB processes");
	for (int i = 0; i < len; i++){
		printf(" job %d at %d", b_times[i].job_number, b_times[i].time_start);
	} 
	printf("\n");

	// print mac C
	printf("\nC processes");
	for (int i = 0; i < len; i++){
		printf(" job %d at %d,", c_times[i].job_number, c_times[i].time_start);
	} 
	printf("\n");

	int t_end = c_times[len-1].time_end;
	int makespan = t_end - t;

	printf("\nThe job processing time interval is [%d, %d], and the makespan is %d\n", t, t_end, makespan); 

	return makespan;
}


/*
    int num_times = num_mac * MAC;

    // initialize johnson's order with -1
    // stores job number, time B, time C
    int j_order[num_mac][MAC+1];
    for (int i = 0; i < num_mac; i++)
        j_order[i][0] = -1;

    // set_jobs is array with job number, time B, time C
    int to_sort[num_times];

    // copy times to to_sort
    for (int i = 0, j = 0; i < num_mac; i++){
        to_sort[j++] = set_jobs[i][MAC-1];
        to_sort[j++] = set_jobs[i][MAC];
    }

    // insertion sort times
    for (int i = 1; i < num_times; i++){
        int key = to_sort[i];
        int k = i - 1;
        while (k >= 0 && to_sort[k] > key){
            to_sort[k + 1] = to_sort[k];
            k--;
        }
        to_sort[k + 1] = key;
    }


    // get smallest elements
    int index = -1;
    int first = 0, last = num_mac-1;
    int exist, smallest;

    // machine 0 is B, 1 is C
    int machine; 

    // get smallest from sorted
    for (int i = 0; i < num_times; i++){

        smallest = to_sort[i];

        // find index of smallest in original
        for (int j = 0; j < num_mac; j++){
            if (set_jobs[j][MAC-1] == smallest){
                index = set_jobs[j][0];
                machine = 0;
            }
            if (set_jobs[j][MAC] == smallest){
                index = set_jobs[j][0];
                machine = 1;
            }
            // check if index exist
            if (index != -1){
                exist = 0;
 
                for (int k = 0; k < num_mac; k++){
                    if (index == j_order[k][0]){
                        exist = 1;
                        break;
                    }
                }
                // store index in place
                if (exist == 0){
                    if (machine == 0){
                        j_order[first][0] = index;
                        j_order[first][MAC-1] = set_jobs[j][MAC-1];
                        j_order[first++][MAC] = set_jobs[j][MAC];
                    }
                    else{
                        j_order[last][0] = index;
                        j_order[last][MAC-1] = set_jobs[j][MAC-1];
                        j_order[last--][MAC] = set_jobs[j][MAC];
                    }
                }
                index = -1;
            }
             
        }
    }

    

    // get start and end times for machine B
    int b_times[num_mac][MAC];
    int pro_time = t;
    for (int job = 0; job < num_mac; job++){
        b_times[job][0] = pro_time;  // start time
        pro_time += j_order[job][MAC-1];
        b_times[job][1] = pro_time;  // end time
    }

    // get start and end times for machine C
    int c_times[num_mac][MAC];
    pro_time = b_times[0][1]; // add if statement for segmentation fault if len b_times is 0 
    for (int job = 0; job < num_mac; job++){
        if (pro_time >= b_times[job][1]){  // decide start time
            c_times[job][0] = pro_time;
        }
        else{
            pro_time = b_times[job][1];
            c_times[job][0] = pro_time;
        }     
        pro_time += j_order[job][MAC];
        c_times[job][1] = pro_time;

    }

    // print Johnson's order
    printf("\nJohnson's order: ");
    for (int x = 0; x < num_mac; x++){
        printf("%d", j_order[x][0]);
        if (x < num_mac-1)
            printf(", ");
    }
   
    // print job information
    printf("\n\nJob information:\n");
    for (int x = 0; x < num_mac; x++){
        printf("Job %d is processed on B starting %d, on C starting %d", 
            j_order[x][0], b_times[x][0], c_times[x][0]);
        if (x < num_mac-1)
            printf(";\n");
        else
            printf(".\n");
    }   

    // print machine information 
    printf("\nMachine information:\n");

    // machine B information 
    printf("B processes");
    for (int x = 0; x < num_mac; x++){
        printf(" job %d at %d", j_order[x][0], b_times[x][0]);
        if (x < num_mac-1)
            printf(",");
        else
            printf(";\n");
    }

    // machine C information 
    printf("C processes");
    for (int x = 0; x < num_mac; x++){
        printf(" job %d at %d", j_order[x][0], c_times[x][0]);
        if (x < num_mac-1)
            printf(",");
        else
            printf(".\n");
    }

    // time interval is first start time on B to last finish ime on C  
    int makespan = c_times[num_mac-1][1]-b_times[0][0];
    printf("\nThe job processing time interval is [%d, %d], and the makespan is %d.\n",
        b_times[0][0], c_times[num_mac-1][1], makespan);

    return makespan;

}*/
