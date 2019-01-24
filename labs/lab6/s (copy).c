/* This program solves a Sudoku puzzle */


#include <stdio.h>

int main(){

  int val, row, col, box;
  int S[81][4]; // row, col, box, val
  int num = 0;

  // read input in 9x9 matrix
  for (row=0; row < 9; row++){
    for (col=0; col < 9; col++){
      scanf("%d", &val);
      // set box to 0 initially
      S[num][0] = row;
      S[num][1] = col;
      S[num][2] = 0;
      S[num][3] = val;
      num++;
    }
  }

  printf("\n\nprinting\n\n");
  int l = 0;
	for (int i=0; i<81; i++){
			printf("%d ", S[i][3]);
			l++;
			if (l==9){
				printf("\n");
				l = 0;
			}
	}
				

  return 0;

}
