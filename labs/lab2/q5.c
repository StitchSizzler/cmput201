/* solves the polynomial 
   3(x^5)+2(x^4)-5(x^3)-(x^2)+7(x)-6 */

#include <stdio.h>

int main(void){
  
  double x, ans;
  printf("Enter x value: ");
  scanf("%lf", &x);

  ans = 3*(x*x*x*x*x)+2*(x*x*x*x)-5*(x*x*x)-(x*x)+7*(x)-6 ;
  printf("%lf\n", ans);

  return 0;
}

