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
    }

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
      
  }// end of read instance



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
