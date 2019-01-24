/* decides if input is palindrome */

# include <stdio.h>
# include <ctype.h>

int main(){

  char str[100];
  char input;
  int index = 0;
  int len = 0;
  printf("Enter a message: ");
  while (((input = getchar()) != '\n') && len<100){
     if (isalpha(input)){
	*(str+len++) = tolower(input);
	     }
  }

  char new_str[100];
  index = 0;
  for (int i = len-1; i>=0; i--){
		*(new_str+index++) = *(str+i);
  }

  // check if same
  int same = 1;
  for (int j = 0; j<len; j++){
     if (*(str+j) != *(new_str+j)){
	  same = 0;
	  break;
     }
  }

  if (same == 1){
     printf("Palindrome\n");
  }
  else{
     printf("Not a Palindrome\n");
  }

  return 0;
}
