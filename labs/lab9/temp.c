double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int newarray[nums1Size+nums2Size];
    for(int i = 0; i < nums1Size; i++)
        newarray[i] = nums1[i];
    for(int i = 0; i < nums2Size; i++)
        newarray[nums1Size+i] = nums2[i];
    
    for (int i = 0; i < nums1Size+nums2Size; ++i) 
        for (int j = i + 1; j < nums1Size+nums2Size; ++j)
            if (newarray[i] > newarray[j]) {
                int a =  newarray[i];
                newarray[i] = newarray[j];
                newarray[j] = a;
            }
    
    int mid = (nums1Size+nums2Size)/2;
    if((nums1Size+nums2Size)%2 == 0)
        return (newarray[mid-1]+newarray[mid])/2.0;
    else
        return newarray[mid];
}
