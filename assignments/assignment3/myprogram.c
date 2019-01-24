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

  int m = 20, n = 200, t1 = 1, t2 = 100, k = 100;
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


	printf("I'm here\n");
  }
*/

	printf("I'm here\n");


/***************** generate random **********************************/



  if(!strcmp(argv[1], "-r")){



	/* stores array of ratios and current index */
	/*
	typedef struct  {
		double ratio[25];  // time high * num instance 
		int index; 
	} Ratios;
	*/

	/*
	typedef struct  {
		double ratio[20000];  // time high * num instance * m/n 
		int index; 
	} Single_Ratios;
	*/

	/* 3d/2d array of Ratios */
	double arr_mn[20][20];  // change to 20*20
	double arr_m[20];
	double arr_n[20];
	//Ratios arr_ratios[125];
	
	

	/* initilize all index to 0 */  // change to 20*28
	/*

	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			printf("i: %d, j: %d\n", i, j);
			int temp = arr_mn[i][j].ratio[0];
			printf("temp: %d\n", temp);
			arr_mn[i][j].index = 0;
			printf("\n");
		}
	}
	*/


/*
	for (int i = 0; i < 20; i++){
		arr_m[i].index = 0;
		arr_n[i].index = 0;
	}
*/




	double r;
	//double matrix[20][20]; // change to 20*20
	//double ratio_m[5], ratio_n[5];
	int idx, idxm, idxn, num_mac = 0, num_j = 0;
	double store, total_ratio = 0;
	
	//int count = 1;

	/* don't change loop values. That's how much they increase by */
	for (int num_machines = 1; num_machines <= m; num_machines++){
	  num_j = 0;
	  for (int num_jobs = 10; num_jobs <= n; num_jobs+=10){
	    for (int time_high = 10; time_high <= t2; time_high+=10){
		for (int num_instance = 1; num_instance <= k; num_instance++){

			Jobs pro_times[num_jobs];


			generate(pro_times, num_machines, num_jobs, time_low, time_high, num_instance);
			r = read_jobs(pro_times, num_machines, num_jobs, time_high, num_instance);

			total_ratio += r;

			/* store ratio for mn pairs*/
				//printf("num_mac: %d, num_j: %d\n", num_mac, num_j);
			//idx = arr_mn[num_mac][num_j].index;
			store = arr_mn[num_mac][num_j];
			store += r;
			arr_mn[num_mac][num_j] = store;
			//printf("passed r: %f\n", r);

			
			/* store ratio for all m */
			//idxm = arr_m[num_mac].index;
			store = arr_m[num_mac];
			store += r;
			arr_m[num_mac] = store;

			
			/* store ratio for all n */
			//idxn = arr_n[num_j].index;
			store = arr_n[num_j];
			store += r;
			arr_n[num_j] = store;

		}
	    }
	    num_j++;
	  }
	  num_mac++;
	}


	/* find and store average of ratios */

     FILE *fp;

	//printf("\n\n");
      char filename[64];
      sprintf(filename, "matrix.txt");
      fp = fopen(filename, "w");


	/* store average ratios for mn */
	double temp, sum, average;
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			/*
			sum = 0;
			for (int x = 0; x < 1000; x++){  // change later
				temp = arr_mn[i][j].ratio[x];
				//printf("temp: %f\n", temp);
				sum += temp;
			}
			*/
			store = arr_mn[i][j];
			average = store/1000;   // change later
			//matrix[i][j] = average;
			fprintf(fp, "%f  ", average);
		}
		fprintf(fp, "\n");
	}


	fprintf(fp, "\n");
	/* store average ratios for m */
	for (int i = 0; i < 20; i++){
		/*
		sum = 0;
		for (int x = 0; x < 20000; x++){
			temp = arr_m[i].ratio[x];
			//printf("temp: %f\n", temp);
			sum += temp;
		}
		*/
		store = arr_m[i];
		average = sum/20000;
		//ratio_m[i] = average;
		fprintf(fp, "%f  ", average);
	}					
	fprintf(fp, "\n\n");


	/* store average ratios for n */
	for (int i = 0; i < 20; i++){
		/*
		sum = 0;
		for (int x = 0; x < 20000; x++){
			temp = arr_n[i].ratio[x];
			//printf("temp: %f\n", temp);
			sum += temp;
		}
		*/
		store = arr_n[i];
		average = sum/20000;
		//ratio_n[i] = average;
		fprintf(fp, "%f  ", average);
	}
	fprintf(fp, "\n\n");

	
	/* store average ratio of all */
	average = total_ratio/400000;
	fprintf(fp, "%f  ", average);


        fclose(fp);





  }



/***********************************************************************/

  return 0;

}// main
