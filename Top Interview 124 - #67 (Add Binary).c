char * addBinary(char * a, char * b) {
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB; //find max length so you know how much memory to allocate
    char*result = (char*) malloc(sizeof(char)*(maxLen+2)); //allocate memory for result
    int carry = 0, sum = 0, idx = 0;
    while (lenA || lenB || carry) {
        int bitA = (lenA) ? a[lenA - 1] - '0' : 0; //convert to integer
        int bitB = (lenB) ? b[lenB - 1] - '0' : 0; 
        sum = bitA ^ bitB ^ carry; //add bits
        carry = (bitA & bitB) | (carry & (bitA ^ bitB)); //carry for next iter, have to consider carry from prev iteration too.
        result[idx++] = sum + '0'; //store calculate sum in result string
        if (lenA) lenA--;
        if (lenB) lenB--;
    }
    result[idx]='\0';
    for (int s = 0, e = idx-1; s < e; s++, e--){ //for loop will go to the middle
        char tmp = result[s];
        result[s] = result[e]; //swap front char with back char
        result[e] = tmp;
    }
    return result;
}
