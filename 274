void swap(int* a, int* b) {
    int tmp = *a; //easy swap using temp variable
    *a = *b;
    *b = tmp;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high]; //
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_element = partition(arr, low, high); //find pivot element using partition
        quickSort(arr, low, pivot_element - 1); //sort 1st half
        quickSort(arr, pivot_element + 1, high); //sort 2nd half
    }
}

int hIndex(int* citations, int citationsSize){
    quickSort(citations, 0, citationsSize -1); //sort all elements
    int hIndex = 0;
    for(int i = 0; i < citationsSize; i++) { //iterate over citation size
        if(citations[i] >= i+1) {
            hIndex = i+1; //increment h index if citations more than number of papers
        } else {
            break;
        }
    }    
    return hIndex;
}
