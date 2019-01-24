/* prints reverse of an input
   uses pointer for index instead of int */

# include <stdio.h>

int main(){

  char str[100];
  char input;
	int index = 0;
	int *p = &index;
	int len = 0;
  while (((input = getchar()) != '\n') && len<100){
		str[*p] = input;
		*p += 1;
		len++;
	}
	str[*p+len] = '\0';

	char new_str[100];
	*p = 0;
	int i = len-1;
	int *p2 = &i;
	for (; *p2>=0;){
		new_str[*p] = str[*p2];
		*p += 1;
		*p2 -= 1;
	}

	new_str[*p] = '\0';
	printf("%s\n", new_str);

  return 0;
}
