/*	Heap Sort
	Make a heap from array.
	Iteratively take the largest element from
	the heap (the root).
 */

void heapify(int to_sort[], int len, int x, int *count);

void heap_sort(int to_sort[], int len, int *count){


	/* create heap by heapifying a tree */
	for (int i = (len/2)-1; i >= 0; i--){
		heapify(to_sort, len, i, count);
	}

	/* move root (max of subarray) to the end */
	for (int i = len-1; i >= 0; i--){
		
		int temp = to_sort[0];
		to_sort[0] = to_sort[i];
		to_sort[i] = temp;

		/* restore heap properties */
		heapify(to_sort, i, 0, count);
	}

	return;
}



void heapify(int to_sort[], int len, int x, int *count){
	
	int left_child = 2*x + 1;
	int right_child = 2*x + 2;
	int max = x;


	*count += 1;
	if (left_child < len && to_sort[left_child] > to_sort[max]){
		max = left_child;
	}	

	*count += 1;
	if (right_child < len && to_sort[right_child] > to_sort[max]){
		max = right_child; 
	}

	if (max != x){
		int temp = to_sort[x];
		to_sort[x] = to_sort[max];
		to_sort[max] = temp;

		/* recurse */ 
		heapify(to_sort, len, max, &count);
	}

	return;

}
