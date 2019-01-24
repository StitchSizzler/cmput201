/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


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
