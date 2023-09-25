double myPow(double x, int n){
if (n==0) return 1.0; //base case of recursion
double half = myPow(x, n/2);
if (n%2 == 0) {return half*half;} //even power
else if (n > 0) {return half * half * x;} //odd power
else {return half*half/x;}} //negative power
