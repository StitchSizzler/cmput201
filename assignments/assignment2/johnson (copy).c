/* Johnson's rule */


#include <stdio.h>

#define MAC 3

/*int set_jobs[], int num_mac, int len, int t*/
int main(){

    //int t = 0;
    int num_mac = 5;
/*
    int set_jobs[num_mac][3] = { 
                                 {3, 29, 28},
                                 {5,  4,  3},
                                 {6, 31, 12},
                                 {9,  2,  1},
                                {10, 14, 24}
                                           }; */

    int set_jobs[3][num_mac] = { 
                                 {3, 5, 6, 9, 10},
                                 {29, 4, 3, 2, 14},
                                 {28, 3, 12, 1, 24}
                                           };

    // set_jovbs is array with job number, time B, time C
    int to_sort[num_mac*2];

    // copy times to to_sort
  /*
    for (int i = 0, j = 0; i < num_mac; i++){
        to_sort[j++] = set_jobs[i][1];
        to_sort[j++] = set_jobs[i][2];  
    }    */

    for (int i = 0, j = 0; i < num_mac*2; j++){
        for (int k = 1; k < MAC; k++){
            to_sort[i++] = set_jobs[k][j];
        }
    }



    for (int x = 0; x < num_mac*2; x++)
        printf("%d ", to_sort[x]);
    printf("\n");
}
