/* From practice midterm question 4 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  int main() {
          int white, black;
          int i, j;

          printf("Enter two positive integers for white and black: ");
          scanf("%d%d", &white, &black);
          printf("white = %d, black = %d\n", white, black);
          srand((unsigned) time(NULL)); /* seed the random number generator */
          while (white + black > 1) {
                  i = rand() % (white + black);
                  j = rand() % (white + black - 1);
                  if (i < white) j++;

                  if (i < white && j < white) {
                          white -= 2;
                          black += 1;
                  }
                  else
                          black -= 1;
          }
          printf("white = %d, black = %d\n", white, black);

          return 0;
  }
