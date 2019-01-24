/*	Merge Sort
	Recursively divide the array into two
	and combine them by comparing first elements.
*/

void merge_sort(int to_sort[], int left, int right, int *count){

	if (left >= right){
		*count += 1;
		return;
	}

	int mid = (left + right)/2;
	merge_sort(to_sort, left, mid, count);
	merge_sort(to_sort, mid+1, right, count);

	/* merge two sorted subarrays */
	int i = left, j = mid+1, k = 0;
	int len = right - left + 1;
	int sorting[len];

	for (; k < len; k++){
		
		*count += 1;
		if (to_sort[i] <= to_sort[j]){
			sorting[k] = to_sort[i++];
			if (i > mid)
				break;
		}
		else{
			sorting[k] = to_sort[j++];
			if (j > right)
				break;
		}
	}


	/* copy remainig subarray */
	for (; j <= right; j++)
		sorting[++k] = to_sort[j];
	for (; i <= mid; i++)
		sorting[++k] = to_sort[i];

	/* copy new array to original */
	for (k = 0; k < len; k++)
		to_sort[left+k] = sorting[k];

	return;
}
