// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


int firstBadVersion(int n) {
  int left = 1, right = n;
  while (left<right) {
    int mid = left + (right-left)/2;
    if (isBadVersion(mid)) {right = mid;} else {left=mid+1;}
  }
  return left;    
}


int firstBadVersion(int n) {
    // Binary search
    int mid = n/2;
    for (int low = 0, high = n; isBadVersion(mid)||!isBadVersion(mid+1); mid = low+(high-low)/2) {
        if (isBadVersion(mid)) {high = mid;} else{low=mid;}
    }
    return mid+1;
}
