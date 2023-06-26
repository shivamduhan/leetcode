bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) {return false;} //cant be anagram if lengths different
    int letters[26] = {0}; //hashmap of letters, store frequency
    for (int i = 0; i < strlen(s); i++) {
        letters[s[i] - 'a']++; //saw letter in s, increment
        letters[t[i] - 'a']--; //decrement freq in t to detect anagram
    }
    for (int i = 0; i < 26; i++) { //all letter freqs should be 0 cus we increment and decrement
        if (letters[i] != 0) {return false;}
    }
    return true;
}
//O(n) time and O(1) space.
