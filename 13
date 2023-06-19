int romanToInt(char * s){
    int num = 0;

    while (*s) { //Iterate through the roman string, character by character
        if (*s == 'I') { //handle special cases for I
            num += (*(s+1) == 'V' || *(s+1) == 'X') ? -1 : 1;
        }
        else if (*s == 'X') { //need to subtract if X is before L or C
            num += (*(s+1) == 'L' || *(s+1) == 'C') ? -10 : 10;            
        }
        else if (*s == 'C') { //C has 2 special cases
            num += (*(s+1) == 'D' || *(s+1) == 'M') ? -100 : 100;
        }
        else if (*s == 'V') {
            num += 5;
        }
        else if (*s == 'L') {
            num += 50;
        }
        else if (*s == 'D') {
            num+=500;
        }
        else if (*s == 'M') {
            num+=1000;
        }
        s++; //go to next character

    }
    return num;

}
