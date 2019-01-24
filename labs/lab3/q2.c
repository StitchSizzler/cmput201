/* Prompts for a 3 digit number 
   and prints it out reversed */

#include <stdio.h>

int main(){
  
  int num, arr[3];
  printf("Enter a 3 digit number: ");
  scanf("%d", &num);

  arr[0] = num % 10;
  arr[1] = num/10 % 10;
  arr[2] = num/10 /10;

  for(int n=0; n<3; n++){
    printf("%d", arr[n]);
  }

  printf("\n");
  

}//main
