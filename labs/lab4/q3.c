/* Reduces a fraction n/m to lowest term */

#include <stdio.h>

int main(){

  int n, m, rem, num1, num2;
  printf("Enter a fraction: ");
  scanf("%d / %d", &num1, &num2);
  n = num1;
  m = num2;

  while(n!=0){
      rem = m % n;
      m = n;
      n = rem;
    }//while

  num1 = num1/m;
  num2 = num2/m;
  printf("In lowest terms: %d/%d\n", num1, num2);

}//main
