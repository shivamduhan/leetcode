void reverse(char*begin, char*end) {
    char swp;
    while (begin < end) {
        swp = *begin;
        *begin++ = *end;
        *end-- = swp;
    }
}

char * reverseWords(char * s){
    //reverse entire string
    int n = strlen(s); //calculate length
    reverse(s, s+n-1); //reversing begins at s ptr, s+n-1 points to the end of the string

    //reverse each word and remove extra spaces
    int i = 0, j = 0; //i is the # of spaces, j is used to traverse string
    while (j < n) { //traverse the length of string
        while (j < n && s[j] == ' ') {
            j++;  // Skip spaces
        }
        if (j == n) break; //end of string, skip to null termination step
        
        if (i > 0) s[i++] = ' '; //convert multiple spaces into 1 space

        // Reverse the word
        char* begin = s + i; //go to the beginning of the word
        while (j < n && s[j] != ' ') {
            s[i++] = s[j++]; //traverse the word
        }
        char* end = s + i - 1; //we hit a space so go back to figure out end of word
        reverse(begin, end); //reverse the word
    }

    // Remove trailing spaces and null terminate the string
    s[i] = '\0';
    return s;
}
