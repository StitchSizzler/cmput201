/*	Quick Sort
	Pick last element as pivot and partition.
	Insert pivot in correct location.
*/


int partition (int to_sort[], int low, int high, int *count);


void quick_sort(int to_sort[], int low, int high, int *count){

	if (low < high){

		int index = partition(to_sort, low, high, count);

		quick_sort(to_sort, low, index-1, count);	
		quick_sort(to_sort, index+1, high, count);
	}
	return;
}


int partition (int to_sort[], int low, int high, int *count){

	int index = low-1;
	int pivot = to_sort[high];

	for (int i = low; i <= high-1; i++){

		*count += 1;
		if (to_sort[i] <= pivot){
			index++;
			int temp = to_sort[index];
			to_sort[index] = to_sort[i];
			to_sort[i] = temp;
		}
	}
	int temp = to_sort[index+1];
	to_sort[index+1] = to_sort[high];
	to_sort[high] = temp;
	return index+1;
}
