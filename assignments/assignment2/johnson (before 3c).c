/* Johnson's rule */


#include <stdio.h>

// machines B and C
#define MAC 2

int johnson(int set_jobs[], int num_mac, int t){

    int t = 0;

    // initialize johnson's order with -1
    int j_order[num_mac];
    for (int i = 0; i < num_mac; i++)
        j_order[i] = -1;

    // set_jovbs is array with job number, time B, time C
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
                    if (index == j_order[k]){
                        exist = 1;
                        break;
                    }
                }
                // store index in place
                if (exist == 0){
                    if (machine == 0)
                        j_order[first++] = index;
                    else
                        j_order[last--] = index;
                }
                index = -1;
            }
             
        }
    }

    // print Johnson's order
    printf("\nJohnson's order: ");
    for (int x = 0; x < num_mac; x++){
        printf("%d ", j_order[x]);
        if (x < num_mac-1)
            printf(", ");
    }

    // print job information
    printf("\nJob information:\n");
    for (int i = 0; i < num_mac; i++){
        printf("Job %d is processed on B starting %d, on C starting %d", j_order[i], mac+1, t);
        if (mac < num_mac-1)
            printf(";\n");
    else
            printf(".\n");
    }


}
