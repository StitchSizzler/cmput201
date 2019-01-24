/* This program computes x^y
   for double x and unsigned int y */

#include <stdio.h>

/* function declaration */
int power(void);

int main(void){
  power();
  return 0;
}

/* do math */
int power(void){
  
  double x;
  unsigned int y;
  double ans=1;
  
  printf("Enter first number: ");
  scanf("%lf", &x);
  printf("Enter second number: ");
  scanf("%u", &y);

  if(y==0){
    ans=1;
  }
  else{
    for(int j=0; j<y; j=j+1){
      ans = ans*x;
    }
  }
    
  printf("%lf\n", ans);  
  return 0;
}
  
