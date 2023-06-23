int candy(int* ratings, int ratingsSize){
    int* candies = (int*)malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1; //create an array of all ones
    }
    for (int i = 1; i < ratingsSize; i++) { //iterate from left to right, ignore 1st cus no left child
        if (ratings[i] > ratings[i-1]) { //if child higher rating than left child
            candies[i] = candies[i-1] + 1; //give child one more candy than left neighbor
        } 
    }
    for (int i = ratingsSize - 2; i >= 0; i--) { //iterate right to left, ignore lost cus no right child
        if (ratings[i] > ratings[i+1]) { //if child higher rating that right child
            candies[i] = candies[i] > candies[i+1] ? candies[i] : candies[i+1] + 1; //give child max of current and 1 more than right neighbor
        }
    }
    int sum = 0;
    for (int i = 0; i < ratingsSize; i++) {
        sum += candies[i]; //calc min number of candies
    }
    free(candies);
    return sum;

}
