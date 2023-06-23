bool isSubsequence(char * s, char * t){
    int i = 0, j = 0;
    while (s[i] && t[j]) { //iterate through both strings completely
        if (s[i] == t[j]) { //if char in s matches char in t
            i++; //now we can check next char in s for a match
        }
        j++; //go thru longer string in every iteration
    }
    return s[i] == '\0'; //if we have iterated through entire s and everything matches, return true
