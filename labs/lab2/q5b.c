/* reads 16 ints and aranges them ino rows of 4
   then fin row an column sums */

#include <stdio.h>

int main(void){

  //Get Numbers
  int arr[4][4];
  printf("Enter the numbers from 1 to 16 in any order:\n ");
    for(int j=0; j<4; j=j+1){
      for(int i=0; i<4; i=i+1){
	scanf("%d", &arr[j][i]);
      }
    }
  
  //Print Matrix
  for(int i=0; i<4; i=i+1){
    for(int j=0; j<4; j=j+1){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  //Row Sum
  printf("Row sums:");
  for(int i=0; i<4; i=i+1){
    int row_sum = 0;
    for(int j=0; j<4; j=j+1){
      row_sum = row_sum + arr[i][j];
    }
    printf(" %d", row_sum);
  }
  printf("\n");

  //Column Sum
  printf("Column sums:");
  for(int i=0; i<4; i=i+1){
    int col_sum = 0;
    for(int j=0; j<4; j=j+1){
      col_sum = col_sum + arr[j][i];
    }
    printf(" %d", col_sum);
  }
  printf("\n");

  //Diagonal1 Sum
  int diag1 = 0;
  for(int i=0; i<4; i=i+1){
    diag1 = diag1 + arr[i][i];
  }

  //Diagonal2 Sum
  int diag2 = 0;
  for(int j=0; j<4; j=j+1){
    diag2 = diag2 + arr[j][3-j];
  }

  printf("Diagonal sums: %d %d \n", diag1, diag2);

  return 0;
}
