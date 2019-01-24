/* Submitting student: Eisha Ahmed        
   Collaborating classmates: n/a
   Other collaborators: n/a
   References: n/a                  */

/* Assignment1
   This program can be run as either -i or -r
   -r will generate random job times
   -i allows the user to input times manually  */

#include "mp.h"
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


     Jobs pro_times[num_jobs];

    printf("Enter in each line the processing times for a job: ");
    for(int i = 0; i < num_jobs; i++){
	pro_times[i].job_number = i+1;
	scanf("%d", &pro_times[i].time_a);
	scanf("%d", &pro_times[i].time_b);
	scanf("%d", &pro_times[i].time_c);
    }

/************************************************************/

  // sort time according to time A and divide into J1 and J2
  
  // insertion sort in descending order
/*
  for (int i = 1; i < num_jobs; i++){
      Jobs key = pro_times[i];
      int k = i - 1;
      while (k >= 0 && pro_times[k].time_a < key.time_a){
          pro_times[k + 1] = pro_times[k];
          k--;
      }
      pro_times[k + 1] = key;
  }
  */
  	// bubble sort in descending order
	for (int i = 0; i < num_jobs-1 ; i++){
		
		for (int j = 0; j < num_jobs-i-1; j++){
			
			if(pro_times[j].time_a < pro_times[j+1].time_a){
				Jobs temp = pro_times[j];
				pro_times[j] = pro_times[j+1];
				pro_times[j+1] = temp;	
			}		
		}		
	}

    

  // divide into J1 and J2
  // num_machines largest go in jobs1, rest in jobs2

  int len_j1, len_j2;
  if (num_jobs > num_machines){ 
	len_j1 = num_machines;
	len_j2 = num_jobs - num_machines;
  }

  else{
	len_j1 = num_jobs;
	len_j2 = -1;	 
  }
 

  int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t;  

  // add times to J1 and J2 and find t1 and t2
  

  if (len_j1 > 0){
  	Jobs jobs1[len_j1];
  	for (int i = 0; i < len_j1; i++){
    		jobs1[i] = pro_times[i];
  	}
 	t1 = lpt(jobs1, len_j1, num_machines, 0);
	t = t1;
  }

  if (len_j2 > 0){ 
  	Jobs jobs2[len_j2];
  	int x = 0;
  	for (int i = num_machines; i < num_jobs; i++){
    		jobs2[x++] = pro_times[i];
  	}
	t2 = johnson(jobs2, len_j2, num_machines, 0);
	if (t2 > t)
		t = t2;
  }

  if (len_j2 > 0){
  	Jobs jobs2[len_j2];
  	int x = 0;
  	for (int i = num_machines; i < num_jobs; i++){
    		jobs2[x++] = pro_times[i];
  	}
 	t3 = lpt(jobs2, len_j2, num_machines, t);
  }
  if (len_j1 > 0){
  	Jobs jobs1[len_j1];
  	for (int i = 0; i < len_j1; i++){
    		jobs1[i] = pro_times[i];
  	}
	t4 = johnson(jobs1, len_j1, num_machines, t);
  }

  int t_temp1 = t + t3;
  int t_temp2 = t + t4;
  int makespan = t_temp1;
  if (t_temp2 > t_temp1)
	makespan = t_temp2;

	printf("\nThe LPT-Johnson schedule has an overall makespan %d\n", makespan); 

  



/*
    // print input values
    printf("\ninstances%d_%d_1.txt\n", num_machines, num_jobs);
    printf("#number of stage 1 machines\n%d\n", num_machines);
    printf("#number of jobs \n%d\n", num_jobs);
    printf("#job processing times \n");

    for(int i = 0; i < num_jobs; i++){
      	printf("Job: %d, ", pro_times[i].job_number);
      	printf("%d ", pro_times[i].time_a);
      	printf("%d ", pro_times[i].time_b);
      	printf("%d ", pro_times[i].time_c);
      
      printf("\n");
    }
    printf("#end of instance \n");

*/


      
  }// end of read instance


/**************************************************************/
  // generate random instance if -r
  // use time as seed for random
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
