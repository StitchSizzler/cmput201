/* Reads a string and prints
   it in reverse order */


# include <stdio.h>

int main(){

  char str[100];
  char input;
	int index = 0;
	int len = 0;
  while (((input = getchar()) != '\n') && len<100){
		str[index++] = input;
		len++;
	}
	str[index] = '\0';

	char new_str[100];
	index = 0;
	for (int i = len-1; i>=0; i--){
		new_str[index++] = str[i];
	}

	new_str[index] = '\0';
	printf("%s\n", new_str);

  return 0;
}
