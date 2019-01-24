/* Merge k Sorted Lists */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
    if (listsSize == 0)
        return NULL;
    
    if (listsSize == 1)
        return lists[0];

    int index = 0;
    struct ListNode head, *current, *previous;
    
    // start head node
    head.next = NULL;
    previous = &head;



    while (index >= 0){
	
	int min = 1000; 

   
        index = -1;

        

        for (int i = 0; i < listsSize; i++){
            if (lists[i] != NULL && (*lists[i]).val < min){
                min = (*lists[i]).val;
                index = i;
            }
        }
        
        if (index >= 0){
            current = malloc(sizeof(*current));
            (*current).val = min;
            (*current).next = NULL;
            (*previous).next = current;
            previous = current;
            if ((*lists[index]).next != NULL){
                lists[index] = (*lists[index]).next;
	    }
	    else{
                lists[index] = NULL;}

	}
		
    }
        
        

    return head.next;
}


/********************************************************************************************/

int main(void)
{
    int i, size;

    struct ListNode *p, *prev, *sorted, dummy1, dummy2, **lists;

    dummy1.next = NULL;
    prev = &dummy1;
    for (i = 0; i < 3; i++) {
        p = malloc(sizeof(*p));
        p->val = i * 2;
        p->next = NULL;
        prev->next = p;
        prev = p;
    }
    for (p = dummy1.next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    dummy2.next = NULL;
    prev = &dummy2;
    for (i = 0; i < 5; i++) {
        p = malloc(sizeof(*p));
        p->val = i * 2 + 1;
        p->next = NULL;
        prev->next = p;
        prev = p;
    }
    for (p = dummy2.next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    size = 2;
    lists = malloc(size * sizeof(struct ListNode *));
    lists[0] = dummy1.next;
    lists[1] = dummy2.next;
    sorted = mergeKLists(lists, size);
    for (p = sorted; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    return 0;
}
