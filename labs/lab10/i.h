#ifndef I_H
#define I_H
#endif

#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

void insertion_sort(int to_sort[], int left, int right, int *count);

struct node *add_to_list(struct node *head, int n, int *count);
