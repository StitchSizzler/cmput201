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
#include "ratio.h"
#include "generate.h"


int main(int argc, char*argv[]){

  int m = 5, n = 50, t1 = 1, t2 = 50, k = 5;
  int time_low = t1;


    time_t t;
    srand((unsigned) time(&t));


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
/*
  if(!strcmp(argv[1], "-i")){
 
	for (int num_machines = 1; num_machines <= m; num_machines++){
	  for (int num_jobs = 10; num_jobs <= n; num_jobs+=10){
	    for (int time_high = 10; time_high <= t2; time_high+=10){
		for (int num_instance = 1; num_instance <= k; num_instance++){




			double ratio = read(pro_times, num_machines, num_jobs, time_high, num_instance);
		}
	    }
	  }
	}


  }

*/

/***************** generate random **********************************/





  if(!strcmp(argv[1], "-r")){

	/* stores array of ratios and current index */
	typedef struct  {
		double ratio[25];
		int index; 
	} Ratios;

	/* 2d array of Ratios */
	Ratios arr_ratio[20][20];  // change to 20*20
	
	/* initilize all index to 0 */  // change to 20*28
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			arr_ratio[i][j].index = 0;
	



	double r;
	double matrix[5][5]; // change to 20*20
	int idx, num_mac = 0, num_j = 0;
	
	//int count = 1;

	for (int num_machines = 1; num_machines <= m; num_machines++){
	  num_j = 0;
	  for (int num_jobs = 10; num_jobs <= n; num_jobs+=10){
	    for (int time_high = 10; time_high <= t2; time_high+=10){
		for (int num_instance = 1; num_instance <= k; num_instance++){

			Jobs pro_times[num_jobs];


			generate(pro_times, num_machines, num_jobs, time_low, time_high, num_instance);
			r = read_jobs(pro_times, num_machines, num_jobs, time_high, num_instance);

			/* store ratio */
				printf("num_mac: %d, num_j: %d\n", num_mac, num_j);
			idx = arr_ratio[num_mac][num_j].index;
			arr_ratio[num_mac][num_j].ratio[idx] = r;
			arr_ratio[num_mac][num_j].index = idx+1;
			//printf("passed r: %f\n", r);

		}
	    }
	    num_j++;
	  }
	  num_mac++;
	}


	/* find and store average of ratios */

     FILE *fp;

	printf("\n\n");
      char filename[64];
      sprintf(filename, "matrix.txt");
      fp = fopen(filename, "w");

	double temp, sum;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			sum = 0;
			for (int x = 0; x < 25; x++){  // change later
				temp = arr_ratio[i][j].ratio[x];
				printf("temp: %f\n", temp);
				sum += temp;
			}
			double average = sum/25;   // change later
			matrix[i][j] = average;
			fprintf(fp, "%f  ", average);
		}
		fprintf(fp, "\n");
	}
        fclose(fp);

	/* store matrix to file */
     /*FILE *fp;

      char filename[64];
      sprintf(filename, "matrix.txt");
      fp = fopen(filename, "w");

	for (int i = 0; )
      fprintf(fp, "%d\n", num_machines);
      fprintf(fp, "%d\n", num_jobs);
	*/

  }


/***********************************************************************/

  return 0;

}// main
