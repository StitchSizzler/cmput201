/* 3Sums */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize) {
    
    // insertion sort
    for (int i = 1; i < numsSize; i++){
        int key = nums[i];
        int k = i - 1;
        while (k >= 0 && nums[k] > key){
            nums[k + 1] = nums[k];
            k--;
        }
        nums[k + 1] = key;
    }
    
    int **ans = NULL;    
    int start, end, current; 
    int index = 0;

    for (int i = 0; i < numsSize; i++){
        
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        
        current = nums[i]*-1;
        start = i+1;
        end = numsSize-1;
        
        while (start < end){
            if (nums[start]+nums[end] == current){
                
                ans=(int **)realloc(ans, sizeof(int *) * index+1);
                ans[index] = (int *) malloc(sizeof(int)*3);
                ans[index][0] = nums[i];
                ans[index][1] = nums[start];
                ans[index++][2] = nums[end];

                start = start+1;
                while (start < end && nums[start] == nums[start-1])
                    start = start + 1;             
            }
            else if (nums[start]+nums[end] < current)
                start = start + 1;
            else
                end = end - 1;
        }
    }
    
    
    *returnSize = index;  /* for printing later */
    return ans;
    

    
}


int main(void)
{
    int i, count;
    int nums[] = { -1, 0, 1, 2, -1, -4 };
    int **triplets = threeSum(nums, sizeof(nums) / sizeof(*nums), &count);
    for (i = 0; i < count; i++) {
        printf("%d %d %d\n", triplets[i][0], triplets[i][1], triplets[i][2]);
    }

    return 0;
}
