char lower(char c){
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}

bool isPalindrome(char * s){
    int start = 0, end = strlen(s) - 1;

    while (start < end) {
        if ((s[start] < 'a' || s[start] > 'z') && (s[start] < 'A' || s[start] > 'Z') && (s[start] < '0' || s[start] > '9')) {
            start++; //if a letter from start is not an alphanumeric char, skip it
        }
        else if ((s[end] < 'a' || s[end] > 'z') && (s[end] < 'A' || s[end] > 'Z') && (s[end] < '0' || s[end] > '9')) {
            end--; //if a letter from end is not an alphanum, skip it
        }
        else {
            if (lower(s[start]) != lower(s[end])) {
                return false; //if the lowercase char from each end doesnt match, not a valid palindrome
            }
            start++; 
            end--;
        }
    }
    return true; //all chars from both ends match


}
