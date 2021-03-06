/* This program finds a maximal matching
   for a given input */

#include <stdio.h>

int main(){

  int size;
  printf("Enter number of vertexs: ");
  scanf("%d", &size);

  //get matrix values
  int matrix[size*size][2];
  int input, v1, v2;
  int count = 0;
  printf("Enter your matrix: ");
  for(int row=0; row<size; row++){
    for(int col=0; col<size; col++){
      scanf("%d", &input);
      if(input==1){
	matrix[count][0] = row+1;
	matrix[count][1] = col+1;
      }
      else if(input==0){
	matrix[count][0] = 0;
	matrix[count][1] = 0;
      }
      else{
	printf("Error in reading\n");
	return -10;
      }
      count += 1;
    }
  }//enter matrix

  //get edges
  int edges[size*size][2];
  for(int j=0; j<size*size; j++){
    edges[j][0]=0;
    edges[j][1]=0;
  }

  int num_edges = 0;
  //get first edge

      
  int empty = 1;
  while(empty){
	printf("ITEERARION...........\n");

  for(int i=0; i<size*size; i++){
    if(matrix[i][0] != 0){
      v1=matrix[i][0];
      v2=matrix[i][1];
      edges[i][0]=v1;
      edges[i][1]=v2;
      num_edges +=1; 
      break;
    }
  }
    empty=0;
    for(int i=0; i<size*size; i++){
      //if v1 or v2 present, eliminate the value
      if((matrix[i][0]==v1)||(matrix[i][1]==v1)){
        //printf("1:%d %d %d\n", v1, matrix[i][0], matrix[i][1]);
	  matrix[i][0]=0;
	  matrix[i][1]=0;
      }
      else if((matrix[i][0]==v2)||(matrix[i][1]==v2)){
        //printf("2:%d %d %d\n", v2, matrix[i][0], matrix[i][1]);
	  matrix[i][0]=0;
	  matrix[i][1]=0;
      }
      else if(matrix[i][0]!=0){
	//edges[i][0]=matrix[i][0];
        //edges[i][1]=matrix[i][1];
        empty=1;
        //printf("%d %d\n", edges[i][0], edges[i][1]);
      }
    }
 }


  for(int i=0; i<size*size; i++){
    if(edges[i][0]!=0){
      printf("%d %d\n", edges[i][0], edges[i][1]);
    }
  }

  return 0;
      


/* while array is not empty (not all 0,0) 
get a new v1, v2, and keep eliminating values with v1, v2.
Make sure to add the original v1, v2 to a separate answer list*/

/* instead of v1 and v2, have something that iterates thorugh 
the list of edges that are already found */
  

 

}//main
