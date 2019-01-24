#include <stdio.h>
#include "lpt.h"

int lpt(int set_jobs[], int num_mac, int len, int t){

    int to_sort[len];
    // copy array into another
    for (int i = 0; i < len; i++)
        to_sort[i] = set_jobs[i];

    // insertion sort
    for (int i = 1; i < len; i++){
        int key = to_sort[i];
        int k = i - 1;
        while (k >= 0 && to_sort[k] > key){
            to_sort[k + 1] = to_sort[k];
            k--;
        }
        to_sort[k + 1] = key;
    }

    // find num_mac largest 
    int largest[num_mac];
    int count = 0;
    int exist = 0;
    int index;

    // get num_mac largest elements
    for (int i = len-1; i >= len-num_mac; i--){ 
        
        // iterate through to_sort to find index
        for (int j = 0; j < len; j++){

            if (set_jobs[j] == to_sort[i]){
                index = j;

                // check if index exist in largest
                exist = 0;
                for (int k = 0; k < count; k++){

                    if (largest[k] == index+1){
                        exist = 1;
                        break;
                    }
                }

                if (exist == 0){
                    largest[count++] = index+1;
                }
            }
        }

    }

    // print lpt
    printf("\nLPT order: ");
    for (int num = 0; num < num_mac; num++){
        printf("%d", largest[num]);
        if (num < num_mac-1)
            printf(", ");
    }

    // print job information
    printf("\nJob information:\n");
    for (int mac = 0; mac < num_mac; mac++){
        printf("Job %d is processed on A_%d starting %d", largest[mac], mac+1, t);
        if (mac < num_mac-1)
            printf(";\n");
        else
            printf(".\n");
    }

    // print machine information
    printf("\nMachine information:\n");
    for (int mac = 0; mac < num_mac; mac++){
        printf("A_%d processes job %d at %d", mac+1, largest[mac], t);
        if (mac < num_mac-1)
            printf(";\n");
        else
            printf(".\n");
    }
 
    printf("The job processing time interval is [%d, %d] and the makespan time is %d\n", 
        t, set_jobs[largest[0]-1], set_jobs[largest[0]-1]-t);

    return 0;   
}

