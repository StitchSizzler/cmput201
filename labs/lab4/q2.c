/* CAlculates Greatest Common Divisor 
   of ints n and m */

#include <stdio.h>

int main(){

  int n, m, rem;
  printf("Enter two integers: ");
  scanf("%d %d", &n, &m);

    while(n!=0){
      rem = m % n;
      m = n;
      n = rem;
    }//while

  printf("Greatest common divisor: %d\n", m);

}//main
