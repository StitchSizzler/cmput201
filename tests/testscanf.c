/* This program contains multiple statements to test outputs of scanf("%c", &ch)
 *
 * Pls be aware of the 'undefined behavior', caused by either c99 or compiler
 *
 */

#include <stdio.h>

int main() {

	int i = 344; //20, 88 or 344;
	char ch = 'X';

	printf("ch = %d, i = \'%c\'\n", ch, i);

	printf("Enter a string for me to read: ");
	while (1) {
		printf("read in %d character: %c\n", scanf("%c", &ch), ch);
		printf("%c\n", ch);
		printf("read in %d more character: ", scanf(" %c", &ch)); /* Can we read in a space by this statement? */
		printf("%c\n", ch);
		printf("read in %d character: ", scanf("%*[^ ]%c", &ch));
		if (ch == ' ')
			break;
		else {
			printf("%c\n", ch);
			printf("\n");
		}
	}
	printf("ch = %c\n", ch);

	return 0;
}

