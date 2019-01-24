/* Creates magic squre of size n^2 where n is odd int
   place 1 in middle of row one. Place the next int
   up one row and over one column. If space occupied,
   place down the row in same column. */

#include <stdio.h>

int main(){

  int size;
  printf("Enter size of magic square: ");
  scanf("%d", &size);
  int square[size][size];
  //set all values to 0
  for(int x=0; x<size; x++){
    for(int y=0; y<size; y++){
      square[x][y] = 0;
    }//for y(col)
  }//for x(row)

  //place 1
  int row = 0;
  int col = size/2;
  int old_row, old_col;
  square[row][col] = 1;

  //place numbers
  for(int num=2; num<=size*size; num++){
    
    //set row
    old_row = row;
    if(row != 0){
      row -= 1;
    }
    else{
      row = size-1;
    }

    //set col
    old_col = col;
    if(col != size-1){
      col += 1;
    }
    else{
      col = 0;
    }

    //check if position empty
    if(square[row][col] == 0){
      square[row][col] = num;
    }
    else{
      //set old_row
      if(old_row != size-1){
	old_row += 1;
      }
      else{
	old_row = 0;
      }

      row = old_row;
      col = old_col;
      square[row][col] = num;
    }
      
    
  }//for num
  
  //print square
  for(int x=0; x<size; x++){
    for(int y=0; y<size; y++){
      printf("%5d", square[x][y]);
    }//for y(col)
    printf("\n");
  }//for x(row)

}//main
  
