void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int ptr = n + m - 1; //ptr to end of merged idx
    int ptr1 = m - 1; //ptr to end of nums1
    int ptr2 = n - 1; //ptr to end of nums2

    while (ptr1 >= 0 && ptr2 >= 0) { //start from end. go to beginning
        if (nums1[ptr1] > nums2[ptr2])
            nums1[ptr--] = nums1[ptr1--]; //select larger element - 1st array
        else
            nums1[ptr--] = nums2[ptr2--]; //select larger element - 2nd array

    }

    while (ptr2 >= 0) {
        nums1[ptr--] = nums2[ptr2--]; //select all from 2nd array
    }

}
