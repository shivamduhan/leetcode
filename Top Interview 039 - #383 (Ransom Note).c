bool canConstruct(char * ransomNote, char * magazine){
    int letters[26] = {0}; //init hashmap
    for(int i = 0; magazine[i] != '\0'; i++) {
        letters[magazine[i]-'a']++; //log frequency of letters in magazine, 0-indexed
    }
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (--letters[ransomNote[i] - 'a'] < 0) { //decrease frequency of used letter
            return false; //if freq is negative, used letter more times than it exists in mag
        }
    }    
    return true; //note can be constructed
}
