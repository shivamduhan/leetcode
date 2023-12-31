int lengthOfLastWord(char * s){
    int len = strlen(s), last_word = 0;

    while (len > 0 && s[len-1]==' '){ //start from end, ignore trailing spaces
        len--;
    } 
    while (len > 0 && s[len-1]!=' '){ //last word has been found
        len--; //start from end of last word, decrement to the beginning
        last_word++; //add to word length, till you encounter space
    }
    return last_word;

}

//Time complexity O(n)
//Space complexity O(1)
