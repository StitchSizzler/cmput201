/* solves for x using this formula: ((((3x+2)x-5)x-1)x+7)x-6 */

#include <stdio.h>

int main(void){
  
  double x, ans;
  printf("Enter x value: ");
  scanf("%lf", &x);

  //ans = ((((3*x+2)x-5)x-1)x+7)-6;
  ans = x*(x*(x*(x*((3*x)+2)-5)-1)+7)-6 ;
  printf("%lf\n", ans);

  return 0;
}

