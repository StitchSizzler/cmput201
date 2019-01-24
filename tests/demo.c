/* From pratice midterm 1 */

#include <stdio.h>

  int main(void) {

     int i = 5, j = 6;
     float x = 7, y = 8;

     printf("Enter values for i, x, j, y: ");
     printf("scanf() reads in %d values: ", scanf("%d %f %d %f", &i, &x, &j, &y));
	   printf("i = %d,  x = %f, j = %d, y = %f\n", i, x, j, y);

	   return 0;
	  }
	  /* end of main */
