/* Testing points:
   - in-\de-crementer (prefix, suffix)
   - short-circuit
   - side effect  */

#include <stdio.h>

int main(){

  int x, y = 11;
  for (x=11; --x>0; x--){
    if (x--<2 && y++>0) x++;
    printf("%d %d\n", x, y);
  }
  printf("%d %d\n", x, y);
}
