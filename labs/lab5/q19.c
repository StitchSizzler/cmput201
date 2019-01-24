/* This program converts decimal into binary */

#include <stdio.h>

void pb(int n);

int main(){
  


  int num;
  printf("Enter a number to convert: ");
  scanf("%d", &num);
	printf("Binary form is: ");
	pb(num);
	printf("\n");

  return 0;

}

void pb(int n){

	if (n != 0){
     pb(n / 2);
     putchar('0' + n % 2);
  }
}


  
