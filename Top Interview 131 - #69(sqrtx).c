int mySqrt(int x){
    double guess = x;
    while (guess*guess-x>0.1) {guess = (guess + x/guess)/2;} //newtons method
    return (int)guess;
}
