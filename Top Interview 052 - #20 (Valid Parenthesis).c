bool isValid(char * s){
    int n = strlen(s);
    // if the length of the string is odd, it can't be valid
    if (n % 2 == 1) {
        return false;
    }

    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[top++] = ch;
        } else {
            if (top == 0) {
                return false;
            }
            char topCh = stack[top - 1];
            if (ch == ')' && topCh != '(') return false;
            if (ch == ']' && topCh != '[') return false;
            if (ch == '}' && topCh != '{') return false;
            top--;
        }
    }
    
    return (top == 0);
}
