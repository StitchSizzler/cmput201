/* pg 217, Q #5
   This program is a modification from lab 4 magic square.
   adds functions create_magic_square and print_magic_square */

#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);



int main(){

  int size;
  printf("Enter size of magic square: ");
  scanf("%d", &size);
  char square[size][size];

  //set all values to 0
  for(int x=0; x<size; x++){
    for(int y=0; y<size; y++){
      square[x][y] = 0;
    }
  }

	create_magic_square(size, square);
	print_magic_square(size, square);

}



void create_magic_square(int n, char magic_square[n][n]){

	//place 1
  int row = 0;
  int col = n/2;
  int old_row, old_col;
  magic_square[row][col] = 1;

  //place numbers
  for(int num=2; num<=n*n; num++){
    
    //set row
    old_row = row;
    if(row != 0){
      row -= 1;
    }
    else{
      row = n-1;
    }

    //set col
    old_col = col;
    if(col != n-1){
      col += 1;
    }
    else{
      col = 0;
    }

    //check if position empty
    if(magic_square[row][col] == 0){
      magic_square[row][col] = num;
    }
    else{
      //set old_row
      if(old_row != n-1){
	old_row += 1;
      }
      else{
	old_row = 0;
      }

      row = old_row;
      col = old_col;
      magic_square[row][col] = num;
    }
      
    
  }//for num

}//create_magic_square


void print_magic_square(int n, char magic_square[n][n]){
	
  for(int x=0; x<n; x++){
    for(int y=0; y<n; y++){
      printf("%5d", magic_square[x][y]);
    }
    printf("\n");
  }

}//print_magic_square
  

  
