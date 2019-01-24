/* sort words from user input
 * each word is no longer than 20 char
 * stop when user enters empty word    */  



//              .___....._               _.....___.
//                  .": o :':         :': o :".
//                  '. '-' .'.       .'. '-' .'
//                    '---'             '---'
//
//          _...----...      ...   ...      ...----..._
//       .-'__..-""'----    '.  '"'  .'    ----'""-..__'-.
//      '.-'   _.--"""'       '-._.-'       '"""--._   '-.
//      '  .-"'                  :                  '"-.  '
//        '   '.              _.'"'._              .'   '
//              '.       ,.-'"       "'-.,       .'
//                '-                           .'
//                  '-._                   _.-'
//                      '"'--...___...--'"'
//
//
// 




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 20

char *words[1000];
int num = 0;

int compare(const void *a, const void *b);
int read_line();

int main(void){


	/* take and store input */
	for (;;){
		printf("Enter a word: ");
		if (read_line() == 0)
			break;
	}


	/* void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) */
	/* compare is the function that compares two elements. User defined (cOoL)*/
	qsort(words, num, sizeof(char *), compare);

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

int compare(const void *a, const void *b){

	return strcmp(*(char **)a, *(char **)b);
}

/* Thanks for being my TA ^_^  */

