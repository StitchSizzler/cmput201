/* Johnson's rule */


#include <stdio.h>
#include "johnson.h"

// machines B and C
#define MAC 2

int johnson(int set_jobs[][MAC+1], int num_mac, int t, int j2[]){


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

}
