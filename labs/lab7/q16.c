/* prints reverse of an input
   uses pointer for index instead of int */

# include <stdio.h>

void reverse(char *message);

int len = 0;

int main(){

  char str[100];
  char input;
	int index = 0;
	int *p = &index;
  while (((input = getchar()) != '\n') && len<100){
		str[*p] = input;
		*p += 1;
		len++;
	}
	str[*p+len] = '\0';

	reverse(str);
	printf("%s\n", str);

  return 0;
}

void reverse(char *message){
	char *p = message;
	char *p2 = message + len-1;
	char temp;
	*(message+len) = '\0';
	while (p != p2 && p-1 != p2){
		temp = *p;
		*p = *p2;
		*p2 = temp;
		p++;
		p2--;
	}
	
}
