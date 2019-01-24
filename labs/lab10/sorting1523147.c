/*
  Bubble Sort  -b
  Selection Sort -s
  Heap Sort -h
  Quick Sort -q
  Merge Sort -m
  Insertion Sort -i
*/


//       /\___/\
//      /       \     __
//     >( ' . ' )>  _/ /
//       '      '._/ /
//       |          |
//       |  _   /_  |
//       \_/ \_/  \_/




#include "sorting1523147.h"


int main(int argc, char*argv[]){

  // check if program run correctly
  // number of arguments should be 2
  // must have -b, -s, -h, -q, -m, or -i
  if(argc!=2){
    printf("%s -b | -s | -h | -q | -m | -i \n", argv[0]);
    return -10;
  }
	
  int len;
  int count = 0;

  printf("Enter the number of integers to be sorted: ");
  scanf("%d", &len);
  int arr[len];

  printf("Enter %d integers to be sorted: ", len);
  for (int i = 0; i < len; i++){
    scanf("%d", &arr[i]);
  }
  
  printf("\nThe input order for the %d integers is \"", len);
  for (int i = 0; i < len; i++){
    printf(" %d", arr[i]);
  }
  printf("\";\n");

  // Bubble Sort
  if(!strcmp(argv[1], "-b")){ 
    bubble_sort(arr, len, &count);
    printf("Bubblesort performs in total %d comparisons;\n", count);
  }

  // Selection Sort
  if(!strcmp(argv[1], "-s")){ 
    selection_sort(arr, len, &count);
    printf("Selectionsort performs in total %d comparisons;\n", count);
  }

  // Heap Sort
  if(!strcmp(argv[1], "-h")){ 
    heap_sort(arr, len, &count);
    printf("Heapsort performs in total %d comparisons;\n", count);
  }

  // Quick Sort
  if(!strcmp(argv[1], "-q")){ 
    quick_sort(arr, 0, len-1, &count);
    printf("Quicksort performs in total %d comparisons;\n", count);
  }

  // Merge Sort
  if(!strcmp(argv[1], "-m")){ 
    merge_sort(arr, 0, len-1, &count);
    printf("Mergesort performs in total %d comparisons;\n", count);
  }

  // Insertion Sort
  if(!strcmp(argv[1], "-i")){ 
    insertion_sort(arr, 0, len-1, &count);
    printf("Insertionsort performs in total %d comparisons;\n", count);
  }


  /* print sorted array */
  printf("The sorted order is \"");
  for (int i = 0; i < len; i ++){
    printf(" %d", arr[i]);
  }
  printf("\".\n");
    
}

