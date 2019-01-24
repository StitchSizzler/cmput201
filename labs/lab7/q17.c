/* decides if input is palindrome */

#include <stdbool.h>
# include <stdio.h>
# include <ctype.h>

bool is_palindrome(const char *message);

int len = 0;

int main(){

  char str[100];
  char input;
  int index = 0;
  printf("Enter a message: ");
  while (((input = getchar()) != '\n') && len<100){
     if (isalpha(input)){
	str[index++] = tolower(input);
	len++;
     }
  }

	bool not_same = is_palindrome(str);
  if (not_same){
     printf("Not a Palindrome\n");
  }
  else{
     printf("Palindrome\n");
  }

  return 0;
}


bool is_palindrome(const char *message){
  // check if same
  const char *p = message;
	const char *p2 = message + len-1;
	while (p != p2 && p-1 != p2){
		if (*p != *p2)
			return 1;
		p++;
		p2--;
	}
	return 0;

}
