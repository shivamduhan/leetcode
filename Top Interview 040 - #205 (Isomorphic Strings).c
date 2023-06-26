bool isIsomorphic(char * s, char * t){
    int map_s[128] = {0}; //create a hashmap that stores frequencies of all 128 ASCII chars
    int map_t[128] = {0}; //s and t need to be compared
    for(int i=0; s[i]!='\0' && t[i]!='\0'; i++){ //iterate through entire s and t
        if(map_s[s[i]] != map_t[t[i]]) return false; //chars cant be replaced
        map_s[s[i]] = i+1; //go next
        map_t[t[i]] = i+1;
    }
    return true; //all char frequencies match
}
