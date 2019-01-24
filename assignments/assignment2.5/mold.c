/* Submitting student: Eisha Ahmed        
   Collaborating classmates: n/a
   Other collaborators: n/a
   References: n/a                  */

/* Assignment1
   This program can be run as either -i or -r
   -r will generate random job times
   -i allows the user to input times manually  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lpt.h"
#include "johnson.h"


int main(int argc, char*argv[]){
  
  int num_machines, num_jobs;
  // check if program run correctly
  // number of arguments should be 2
  // must have -i or -r
  if(argc!=2){
    printf("%s -i | -r \n", argv[0]);
    return -10;
  }
  if(strcmp(argv[1], "-i") && strcmp(argv[1], "-r")){
    printf("%s -i | -r \n", argv[0]);
    return -10;
  }

  // read instance if -i
  // quit program if invalid input
  if(!strcmp(argv[1], "-i")){
    printf("Enter the number of machines in stage 1: ");
    if(scanf("%d", &num_machines)==0 || num_machines<0){
      printf("Error in reading the instance!\n");
      return -10;
    }
    printf("Enter the number of jobs: ");
    if(scanf("%d", &num_jobs)==0 || num_jobs<0){
      printf("Error in reading the instance!\n");
      return -10;
    }

    // array to store valid job times from input
    int pro_times[num_jobs][3];
    int set_jobs[num_jobs];
    printf("Enter in each line the processing times for a job: ");
    for(int job_count=0; job_count<num_jobs; job_count++){
      for(int time_count=0; time_count<3; time_count++){
		if(scanf("%d", &pro_times[job_count][time_count])==0){
		  printf("Error in reading the instance!\n");
		  return -10;
		}
		if(pro_times[job_count][time_count]<0){
		  printf("Error in reading the instance!\n");
		  return -10;
		}
      }
      set_jobs[job_count] = pro_times[job_count][0];
    }

    //********************************LPT Johnson Stuff****************************//

    int t = 0, count = 0, exist; 
    int j1[num_jobs]; // for lpt
    int j2[num_jobs]; // for johnson 
    // intitialize j1 and j2 with -1
    for(int i = 0; i < num_jobs; i++){
        j1[i] = -1;
        j2[i] = -1;
    }

    // get lpt times
    int t1 = lpt(set_jobs, num_machines, num_jobs, t, j1);
    
    // get remaining times for johnson
    int j_jobs[num_jobs - num_machines][3];
    if (num_jobs > num_machines){


        for (int x = 1; x <= num_jobs; x++){
            // if not in j1, add to j2

            // check if index exist in j1
            exist = 0;
            for (int k = 0; k < num_machines; k++){

                if (j1[k] == x){
                    exist = 1;
                    break;
                }
            }
            if (exist == 0){
                j2[count++] = x;
            }
        }
    }
    for (int i = 0; i < num_machines; i++){
        // job#, time B, time C
        j_jobs[i][0] = j2[i];
        j_jobs[i][1] = pro_times[j2[i]-1][1];
        j_jobs[i][2] = pro_times[j2[i]-1][2];
    }

    // count is the number of jobs left from lpt
    int t2 = johnson(j_jobs, count, t, j2);

    // set t = max{t1, t2}
    if (t1 > t2)
        t = t1;
    else
        t = t2;


    // make new job array for 2nd lpt call
    int new_jobs[num_jobs];
    for (int x = 0; x < num_jobs; x++)
        new_jobs[x] = 0;
 
    int j_index;

    for (int x = 0; x < count; x++){
        j_index = j_jobs[x][0]-1;
        new_jobs[j_index] = pro_times[j_index][0];
}

    
    int t3 = lpt(j1, num_machines, num_jobs, t, j1);
    int j3;
    int t4 = johnson(set_jobs, count, t, j3);

    int tmax;
    if (t+t3 > t+t4)
        tmax = t+t3;
    else
        tmax = t+t4;

    printf("The LPT-Johnson schedule has an overall makespan %d\n.", tmax);

    //*****************************************************************************//
/*
    // print input values
    printf("\ninstances%d_%d_1.txt\n", num_machines, num_jobs);
    printf("#number of stage 1 machines\n%d\n", num_machines);
    printf("#number of jobs \n%d\n", num_jobs);
    printf("#job processing times \n");

    for(int job_count=0; job_count<num_jobs; job_count++){
      for(int time_count=0; time_count<3; time_count++){
	printf("%-3d ", pro_times[job_count][time_count]);
      }
      printf("\n");
    }
    printf("#end of instance \n");
 */     
  }// end of read instance




  //**************************************************************//
  // generate random instance if -r
  // use as seed for random
  // quit program if invalid input
  if(!strcmp(argv[1], "-r")){
    int time_low, time_high, num_instances;
    time_t t;
    srand((unsigned) time(&t));
    printf("Generating random instance ... \n");
    printf("Enter the number of machines in stage 1: ");

    if(scanf("%d", &num_machines)==0 || num_machines<0){
      printf("Error in reading the instance!\n");
      return -10;
    }
    printf("Enter the number of jobs: ");
    if(scanf("%d", &num_jobs)==0 || num_jobs<0){
      printf("Error in reading the instance!\n");
      return -10;
    }
    printf("Enter the processing time interval [t_1, t_2]: ");
    if(scanf("%d %d", &time_low, &time_high)==0 || time_low<0 || time_high<0){
      printf("Error in reading the instance!\n");
      return -10;
    }
    printf("Enter the number of instances to be generated: ");
    if(scanf("%d", &num_instances)==0 || num_instances<0){
      printf("Error in reading the instance!\n");
      return -10;
    }

    for(int instance_num=1; instance_num<=num_instances; instance_num++){
      printf("\n#instance%d_%d_%d.txt\n", num_machines, num_jobs, instance_num);
      printf("#number of stage 1 machines\n%d\n", num_machines);
      printf("#number of jobs \n%d\n", num_jobs);
      printf("#job processing times\n");

      // print random times
      // set random within range
      for(int job=0; job<num_jobs; job++){
	for(int time_count=0; time_count<3; time_count++){
	  int rand_time = rand()% (time_high+1-time_low)+time_low;
	  printf("%-3d ", rand_time);
	}
	printf("\n");
      }
      printf("#end of instance\n\n");
    }

  }// end of generate random instance 

  return 0;

}// main


