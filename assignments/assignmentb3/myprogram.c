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
#include "read.h"
#include "generate.h"


int main(int argc, char*argv[]){
  
  int num_machines, num_jobs;

  int m = 5, n = 10, t1 = 1, t2 = 10, k = 1;
  int time_low = t1;


/************** validate ***********************************/
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


/******************* read ************************************/

  if(!strcmp(argv[1], "-i")){
 
	for (int num_machines = 1; num_machines <= m; num_machines++){
	  for (int num_jobs = 10; num_jobs <= n; num_jobs+=10){
	    for (int time_high = 10; time_high <= t2; time_high+=10){
		for (int num_instance = 1; num_instance <= k; num_instance++){

			int makespan = read(num_machines, num_jobs, time_high, num_instance);
		}
	    }
	  }
	}


  }



/***************** generate random **********************************/


  if(!strcmp(argv[1], "-r")){
	
	//int count = 1;

	for (int num_machines = 1; num_machines <= m; num_machines++){
	  for (int num_jobs = 10; num_jobs <= n; num_jobs+=10){
	    for (int time_high = 10; time_high <= t2; time_high+=10){
		//printf("\ncount: %d\n", count++);
		generate(num_machines, num_jobs, time_low, time_high, k);
	    }
	  }
	}


  }


/***********************************************************************/

  return 0;

}// main
