/* decides if input is palindrome */

# include <stdio.h>
# include <ctype.h>

int main(){

  char str[100];
  char input;
  int index = 0;
	int *p = &index;
  int len = 0;
  printf("Enter a message: ");
  while (((input = getchar()) != '\n') && len<100){
     if (isalpha(input)){
		str[*p] = tolower(input);
		*p += 1;
		len++;
     }
  }

  char new_str[100];
  *p = 0;
	int i = len-1;
	int *p2 = &i;
  for (; *p2>=0;){
      new_str[*p] = str[*p2];
			*p += 1;
			*p2 -= 1;
  }

  // check if same
  int same = 1;
	*p = 0;
  for (; *p<len;){
     if (str[*p] != new_str[*p]){
	  same = 0;
	  break;
     }
		*p += 1;
  }

  if (same == 1){
     printf("Palindrome\n");
  }
  else{
     printf("Not a Palindrome\n");
  }

  return 0;
}
