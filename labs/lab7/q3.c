/* prints reverse of an input
   uses pointer for index instead of int */

# include <stdio.h>

int main(){

  char str[100];
  char input;
	int len = 0;
  while (((input = getchar()) != '\n') && len<100){
		*(str+len++) = input;
	}
	*(str+1+len) = '\0'; // end of string

	int index = 0;
	char new_str[100];
	for (int i = len-1; i>=0; i--){
		*(new_str+index++) = *(str+i);
	}
	*(new_str+index) = '\0';  // adding to last

	printf("%s\n", new_str);

  return 0;
}
