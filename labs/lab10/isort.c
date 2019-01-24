/*	Insertion Sort
	Find the smallest element in subarray
	and insert it to the right place, shifting
	all the elements after it.
*/

#include <stdio.h>
#include "i.h"

void insertion_sort(int to_sort[], int left, int right, int *count){

	int i;
	struct node *head;
	struct node *p;

	head = malloc(sizeof(struct node));
	if (head == NULL){
		printf("Error: malloc failed in i.c\n");
		exit(1);
	}
	

	head->value = to_sort[left];
	head->next = NULL;

	for (i = left+1; i <= right; i++){
		head = add_to_list(head, to_sort[i], count);
	}
	
	for (i = left; i <= right; i++){
		to_sort[i] = head->value;
		p = head;
		head = head->next;
		free(p);
	}

	return;
}


struct node *add_to_list(struct node *head, int n, int *count){

	struct node *new_node;
	struct node *p, *q;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL){
		printf("Error: malloc failed in i.c\n");
		exit(1);
	}
	new_node->value = n;

	*count += 1;
	if (head->value > new_node->value){
		new_node->next = head;
		head = new_node;
		return head;
	}

	p = head;
	q = p->next;
	while (q != NULL && q->value <= n){
		*count += 1;
		p = q;
		q = p->next;
	}
	*count += 1;

	if (q != NULL){
		new_node->next = q;
		p->next = new_node;
	}
	else{
		new_node->next = NULL;
		p->next = new_node;
	}
	return head;
}
