/* read instance for -i */


#include "mp.h"
#include "lpt.h"
#include "johnson.h"

double ratio (double l1, int l2, int s);

double find_l1(Jobs *jobs, int num_machines, int num_jobs);

double read_jobs(Jobs *pro_times, int num_machines, int num_jobs, int time_high, int instance_num){


/************************************************************/


  // sort time according to time A and divide into J1 and J2
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
  int s = t_temp1;
  if (t_temp2 > t_temp1)
	s = t_temp2;

//	printf("\nThe LPT-Johnson schedule has an overall makespan %d\n", s); 

	
	double l1 = find_l1(pro_times, num_machines, num_jobs);
	int l2 = johnson(pro_times, num_jobs, num_machines, 0);
	double r = ratio(l1, l2, s);
	

	return r;

      
  }// end of read instance


double ratio (double l1, int l2, int s){

	double l = l1;
	if (l2 > l)
		l = l2;

	double  r = s/l;

	//printf("l2 is: %d\n", l2);
	//printf("s is: %d\n", s);
	//printf("r is: %f\n", r);

	return r;

}

double find_l1(Jobs *jobs, int num_machines, int num_jobs){

	int sum = 0;
	int a1 = jobs[0].time_a;

	for (int i = 0; i < num_jobs-1; i++){
		sum += jobs[i].time_a;
	}


	double temp = sum / num_machines;

	double l1 = temp;
	if (a1 > l1)
		l1 = a1;

	//printf("sum is: %d\n", sum);
	//printf("sum/m is: %f\n", temp);
	//printf("a1 is: %d\n", a1);
	//printf("l1 is: %f\n", l1);

	return l1;

}

