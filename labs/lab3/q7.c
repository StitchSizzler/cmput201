/* Finds the largest and smallest of 4 ints */

#include <stdio.h>

int main(){

  int i1, i2, i3, i4;
  printf("Enter four integers: ");
  scanf("%d%d%d%d", &i1, &i2, &i3, &i4);
  int arr[4] = {i1, i2, i3, i4};

  int largest = i1;
  int smallest = i1;

  for(int i=1; i<4; i++){
    if(arr[i]>largest){
      largest = arr[i];
    }//if, largest
    else if(arr[i]<smallest){
      smallest = arr[i];
    }//else if, smallest
  }//for, i<3

  printf("Largest: %d\n", largest);
  printf("Smallest: %d\n", smallest);

}//main
