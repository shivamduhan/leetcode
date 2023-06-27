int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp; //need sum of squares
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {
    int slow = n, fast = digitSquareSum(n); //detect cycles
    while (slow!=fast) {
        slow = digitSquareSum(slow); //slow is updated once
        fast = digitSquareSum(digitSquareSum(fast)); //fast is updated twice        
        }
    return slow == 1;
}
