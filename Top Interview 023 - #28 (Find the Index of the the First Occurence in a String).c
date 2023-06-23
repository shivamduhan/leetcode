int strStr(char * haystack, char * needle){
    int haystack_len = strlen(haystack), needle_len = strlen(needle);
    if (needle_len == 0) {
        return 0; //trivial case: needle is empty string so return 0th index
    }
    for (int i = 0; i <= haystack_len - needle_len; i++) { //only iterate till strlen(haystack) - strlen(needle) not strlen(haystack) cus needle cant fit in the remaining haystack
        if (strncmp(haystack+i, needle, needle_len) == 0) { //starting from ith index of haystack, compare substring of length needle_length with the actual needle
            return i; //strncmp returns 0, so we found the needle
        }
    }
    return -1; //didnt find needle
    }
