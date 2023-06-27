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
    int slow = n, fast = n; //detect cycles
    while (true) {
        slow = digitSquareSum(slow); //slow is updated once
        fast = digitSquareSum(digitSquareSum(fast)); //fast is updated twice
        if (slow == fast) {
            if (slow == 1)
                return true; //process ends in 1
            else
                return false;
        }
    }
}
