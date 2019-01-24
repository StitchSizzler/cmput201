/* Find middle of array A and array B.
 * True median lies between median A and median B */





double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int combine[nums1Size+nums2Size];
    for(int i = 0; i < nums1Size; i++)
        combine[i] = nums1[i];
    for(int i = 0; i < nums2Size; i++)
        combine[nums1Size+i] = nums2[i];
    
    for (int i = 0; i < nums1Size+nums2Size; i++) 
        for (int j = i + 1; j < nums1Size+nums2Size; j++)
            if (combine[i] > combine[j]) {
                int temp =  combine[i];
                combine[i] = combine[j];
                combine[j] = temp;
            }
    
    int median = (nums1Size+nums2Size)/2;
    if((nums1Size+nums2Size)%2 == 0)
        return (combine[median-1]+combine[median])/2.0;
    else
        return combine[median];
}
   
