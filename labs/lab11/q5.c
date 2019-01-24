/* sort words from user input
 * each word is no longer than 20 char
 * stop when user enters empty word    */  


//       /\___/\
//      /       \     __
//     >( ' . ' )>  _/ /
//       '      '._/ /
//       |          |
//       |  _   /_  |
//       \_/ \_/  \_/






#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 20

char *words[1000];
int num = 0;

int read_line();

int main(void){


	/* take and store input */
	for (;;){
		printf("Enter a word: ");
		if (read_line() == 0)
			break;
	}

		/* sort words */
		for (int i = 0; i < num; i++){
			int first = i;
			for (int j = i + 1; j < num; j++){
				if (strcmp(words[j], words[first]) < 0)
					first = j;
			}
			char *temp = words[first];
			words[first] = words[i];
			words[i] = temp;
			
		}

	printf("In sorted order: ");
	for (int i = 0; i < num; i++){
		printf("%s ", words[i]);
	}
	printf("\n");

	return 0;

}


int read_line(){

	words[num] = malloc(LEN + 1);
	int ch, i = 0;

	if (!words[num]){
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
	}

  	while ((ch = getchar()) != '\n')
    		if (i < LEN)
      			words[num][i++] = ch;
    		else if (ch == ' ')
      			break;

  	words[num][i] = '\0';
  	num++;

	return i;
}

