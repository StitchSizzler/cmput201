/*	Bubble Sort 
	Largest value "bubbles up" the array.
	At the end of each iteration, the ith 
	largest value is in it's place.
*/


void bubble_sort(int to_sort[], int len, int *count){


	for (int i = 0; i < len-1 ; i++){
		
		for (int j = 0; j < len-i-1; j++){
			
			*count += 1;
			if(to_sort[j] > to_sort[j+1]){
				/* swap j and j+1 */
				int temp = to_sort[j];
				to_sort[j] = to_sort[j+1];
				to_sort[j+1] = temp;	
			}		
		}		
	}

	return; 

}
