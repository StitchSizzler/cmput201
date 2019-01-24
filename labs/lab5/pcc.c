/* Classifies a poker hand */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
bool royal_straight, straight, ace_low, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(int num_in_rank[], int num_in_suit[]);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void){
	int num_in_rank[NUM_RANKS];
	int num_in_suit[NUM_SUITS];
	for(;;){
		read_cards(num_in_rank, num_in_suit);
		analyze_hand(num_in_rank, num_in_suit);
		print_result();
	}
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(int num_in_rank[], int num_in_suit[]){
	bool card_exists[NUM_RANKS][NUM_SUITS];
	char ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_card;
	int cards_read = 0;

	for (rank = 0; rank < NUM_RANKS; rank++){
		num_in_rank[rank] = 0;
		for (suit = 0; suit < NUM_SUITS; suit++)
			card_exists[rank][suit] = false;
	}

	for (suit = 0; suit < NUM_SUITS; suit++)
		num_in_suit[suit] = 0;

	while (cards_read < NUM_CARDS){
		bad_card = false;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch (rank_ch){
			case '0':						exit(EXIT_SUCCESS);
			case '2':						rank = 0; break;
			case '3':						rank = 1; break;
			case '4':						rank = 2; break;
			case '5':						rank = 3; break;
			case '6':						rank = 4; break;
			case '7':						rank = 5; break;
			case '8':						rank = 6; break;
			case '9':						rank = 7; break;
			case 't':	case 'T':	rank = 8; break;
			case 'j':	case 'J':	rank = 9; break;
			case 'q':	case 'Q':	rank = 10; break;
			case 'k':	case 'K':	rank = 11; break;
			case 'a': case 'A':	rank = 12; break;
			default:						bad_card = true;
		}

		suit_ch = getchar();
		switch (suit_ch){
			case 'c':	case 'C':	suit = 0; break;
			case 'd':	case 'D':	suit = 1; break;
			case 'h':	case 'H':	suit = 2; break;
			case 's':	case 'S':	suit = 3; break;
			default:						bad_card = true;
		}

		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_card = true;

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card_exists[rank][suit])
			printf("Duplicate card; ignored.\n");
		else{
			num_in_rank[rank]++;
			num_in_suit[suit]++;
			card_exists[rank][suit] = true;
			cards_read++;
		}
	}
}

/*********************************************************
 * analyze_hand: Determines whether the hand contains a  *
 *               straight, a flush, four-of-a-kind,      *
 *               and/or three-of-a-kind; determines the  *
 *               number of pairs; stores the results into*
 *               the external variables straight, flush, *
 *               four, three, and pairs.                 *
 *********************************************************/
void analyze_hand(int num_in_rank[], int num_in_suit[]){
	int num_consec = 0;
	int rank, suit;
	royal_straight = false;
	straight = false;
	ace_low = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	for (suit = 0; suit < NUM_SUITS; suit++)
		if (num_in_suit[suit] == NUM_CARDS)
			flush = true;

	/* check for straight */
	rank = 0;
	bool t_exist = false;
	bool a_exist = false;
	bool two_exist = false;
	bool five_exist = false;
	while (num_in_rank[rank] == 0) rank++;
	for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++){

		/* check for royal straight*/
		if (rank == 8)				t_exist = true;
		if (rank == 12)				a_exist = true;

		num_consec++;
	}

	if (num_consec == NUM_CARDS){
		straight = true;
		if (t_exist && a_exist)
			royal_straight = true;
		return;
	}

	/* check for ace-low straight */
	a_exist = false;
	if (num_consec == NUM_CARDS-1){
			if (num_in_rank[12] > 0)	a_exist = true;
			if (num_in_rank[0] > 0)		two_exist = true;
			if (num_in_rank[3] > 0)		five_exist = true;
			if (two_exist == true && five_exist == true && a_exist ==true)
				ace_low = true;
	}


	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (rank = 0; rank < NUM_RANKS; rank++){
		if (num_in_rank[rank] == 4) four = true;
		if (num_in_rank[rank] == 3) three = true;
		if (num_in_rank[rank] == 2) pairs++;
	}
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void){
	if (royal_straight && flush)				printf("Royal flush");
	else if (straight && flush)	printf("Straight flush");
	else if (four)					printf("Four of a kind");
	else if (three &&
					 pairs == 1)		printf("Full house");
	else if (flush)					printf("Flush");
	else if (straight)			printf("Straight");
	else if (ace_low)				printf("Ace-low straight");
	else if (three)					printf("Three of a kind");
	else if (pairs == 2)		printf("Two pairs");
	else if (pairs == 1)		printf("Pair");
	else										printf("High card");

	printf("\n\n");
}
