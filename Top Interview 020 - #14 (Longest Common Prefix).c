char * longestCommonPrefix(char ** strs, int strsSize){
if (strsSize == 0) {
    return "";
}
for (int idx = 0; idx < strlen(strs[0]); idx++) { //loop over char of first word cus longest possible prefix is the whole first word
    char c = strs[0][idx]; //isolate characters in 1st word
    for (int i =0; i<strsSize; i++) { //go to next word
        if ((idx == strlen(strs[i])) || (strs[i][idx] != c)) { //if youre at the end of the word or if the current word no longer matches prefix, terminate the prefix.
            strs[0][idx] = '\0';
        }
    }
}
return strs[0]; //have to return the prefix
}
