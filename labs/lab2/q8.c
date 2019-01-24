/* calculates remaining balance on loan
   after first, second, third monthly payments */

#include <stdio.h>

int main(void){

  double loan, rate, pay;

  printf("Enter amount of loan: ");
  scanf("%lf", &loan);
  printf("Enter interest rate: ");
  scanf("%lf", &rate);
  printf("Enter monthly payment: ");
  scanf("%lf", &pay);

  rate = (rate/100)/12;

  loan = loan-pay+(rate*loan);
  printf("\nBalance remaining after first payment: $%.2lf \n", loan);
  loan = loan-pay+(rate*loan);
  printf("Balance remaining after second payment: $%.2lf \n", loan);
  loan = loan-pay+(rate*loan);
  printf("Balance remaining after third payment: $%.2lf  \n", loan);

  return 0; 
}
