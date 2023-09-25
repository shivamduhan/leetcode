int trailingZeroes(int n){
    int cnt = 0;
    while (n) { //this is logarithmic time because you divide by 5 in every iteration
        n /= 5; //only need to consider factors of 5 cus 2*5 = 10
        cnt = n + cnt;
    }
    return cnt;
}
