/* generate random instances */

#include "mp.h"
#include "lpt.h"
#include "johnson.h"

int generate(Jobs *pro_times, int num_machines, int num_jobs, int time_low, int time_high, int num_instance){

  // use time as seed for random
  // quit program if invalid input

/*
    time_t t;
    srand((unsigned) time(&t));*/


     FILE *fp;

      char filename[64];
      sprintf(filename, "%s//instance%d_%d_%d_%d.txt","test", num_machines, num_jobs, num_instance, time_high);
      fp = fopen(filename, "w");

      fprintf(fp, "%d\n", num_machines);
      fprintf(fp, "%d\n", num_jobs);

      // print random times
      // set random within range
      for(int job=0; job<num_jobs; job++){
	for(int time_count=0; time_count<3; time_count++){
	  int rand_time = rand()% (time_high+1-time_low)+time_low;
	  fprintf(fp, "%-3d ", rand_time);
	  if (time_count == 0)
	  	pro_times[job].time_a = rand_time;
	  else if (time_count == 1)
		pro_times[job].time_b = rand_time;
	  else
		pro_times[job].time_c = rand_time;
	}
	fprintf(fp, "\n");
      }
      //printf("#end of instance\n\n");

    fclose(fp);
/*
job, macines, low time, high time
array[][] = job*procceing time

read(fp, machines, job, low, time, high time, array[][])
*/

    

    return 0;

}// end of generate random instance 
