/*	Selection Sort 
	Find the minimum in each subarray
	and add it to place.
 */

void selection_sort(int to_sort[], int len, int *count){
	
	int index; /* index of minimum */

	for (int i = 0; i < len-1; i++){
		
		index = i;

		/* start subarray after ith minimum */
		for (int j = i+1; j < len; j++){
			
			*count += 1;
			if (to_sort[j] < to_sort[index]){
				index = j;
			}
		}

		/* swap new minimum with first element in subarray */
		int temp = to_sort[index];
		to_sort[index] = to_sort[i];
		to_sort[i] = temp;
	}
	return;

}
