/* This program solves a Sudoku puzzle */


#include <stdio.h>

int S[9][9];
int find_empty(int *row, int *col);
int is_safe(int num, int r, int c);
int play();


int main(){

  // scan matrix
	int val;
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col++){
			scanf("%d", &val);
			S[row][col] = val;
		}
	}


	play();
		// print matrix
		printf("\n\n");
		for (int row = 0; row < 9; row++){
			for (int col = 0; col < 9; col++){
				printf("%d ", S[row][col]);
			}
			printf("\n");
		}
	

	return 0;

}

int find_empty(int *row, int *col){

	int num_empty = 0;
	int r, c;
	for (r = 0; r < 9; r++){
		for (c = 0; c < 9; c++){
			if (S[r][c] == 0){
				*row = r;
				*col = c;
				num_empty = 1;
				return num_empty;	
			}
		}
	}
	return num_empty; 
}


// check if number can be placed
int is_safe(int num, int row, int col){

	int r, c, start_row, start_col;

	// for the row, check each column
	//  to see if num exists 
	for (c = 0; c < 9; c++){
		if (S[row][c] == num){
			return 0;   // num exists
		}
	}

	// for the column, check each row
	// to see if num exists
	for (r = 0; r < 9; r++){
		if (S[r][col] == num){
			return 0;   // num exists
		}
	}

	// check box
	start_row = (row/3)*3;
	start_col = (col/3)*3;
	for (r = start_row; r < start_row+3; r++){
		for (c = start_col; c < start_col+3; c++){
			if (S[r][c] == num){
				return 0;   // num exists
			}
		}
	}
	return 1;   // num does not exist
}
	
// solve the sudoku 
int play(){

	int row, col, empty, num, safe;
	
	empty = find_empty(&row, &col);
	if (empty == 0){
		return 1;
	}
	
	// check for all numbers
	for (num = 1; num <= 9; num++){
		safe = is_safe(num, row, col);
		if (safe){
			S[row][col] = num;
			if(play()){
				return 1;
			} // reassign if solution not good
			S[row][col] = 0;
		}
	}
	return 0;
	
}

/*
int find_empty(int S[9][9]){
	
	int num_empty = 0;
	int num_info[3];
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col++){
			if (S[row][col] == 0){
				num_empty = 1;
				num_info[0] = num_empty;
				num_info[1] = row;
				num_info[2] = col;
				return num_info;
			}
		}
	}
	num_info[0] = num_empty;
	num_info[1] = -1;
	num_info[2] = -1;
	return num_info;

}
*/

	
