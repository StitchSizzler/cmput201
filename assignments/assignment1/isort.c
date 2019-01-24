// insertion sort

#include <stdio.h>

int lpt(int set_jobs[], int t, int len);

int main(){

    int arr[5] = {9, 8, 3, 6, 1};
    lpt(arr, 3, 5);

}

int lpt(int set_jobs[], int t, int len){

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

    // find t largest 
    int largest[t];
    int tnum = 0;
    int count = 0;
    int exist = 0;
    int index;

    // get t largest elements
    for (int i = len-1; i >= len-t; i--){ 
        
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






/*
         exist = 0;
                    printf("count: %d\n", count);
         // check if index exist
         for (int j = 0; j < count; j++){
            if (i == largest[j]){
                exist = 1;
                    printf("exist: %d\n", to_sort[i]);
                break;
            }
        }
        // find index to store
        if (exist == 0){
                    printf("ADDING %d\n", to_sort[i]);
            for (int k = 0; k < len; k++){
                if (to_sort[i] == set_jobs[k]){
                    largest[count++] = k+1;
                    break;
                }
            }
        }

*/

    }



    for (int num = 0; num < 3; num++)
        printf("%d ", largest[num]);
    printf("\n");

 
    return 0;   
}

