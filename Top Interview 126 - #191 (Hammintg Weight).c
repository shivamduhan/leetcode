int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) { //repeat till number not 0
        if (n & 1) cnt++; //check if right most bit is 1
        n >>= 1; //shift out right bit
    }
    return cnt; //return number of 1s
}
