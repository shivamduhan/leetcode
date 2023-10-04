void reverse(char * string) { //trivial
  int len = strlen(string);
  for (int iter = 0; iter < len/2; iter++){ //swap characters till you reach the middle
    char tmp = string[iter]; 
    string[iter] = string[len-iter-1];
    string[len-iter-1] = tmp;
  }
}
char * toHex(int num){
  if (!num){return "0";} //trivial
  char*hex = (char*)malloc(9*sizeof(char)); //max size of hex is 8 chars + null terminator
  char* dict = "0123456789abcdef"; //reference to convert num to hex
  int index = 0; //keeep track of pos in final hex string
  while (num && index < 8){ //make sure you dont read past 32 bits
    hex[index++] = dict[num&0xf]; //isolate lower 4 bits of the number and convert to hex char using ref
    num = num >> 4; //shift out the 4 bits you just converted to hex.
  }
  hex[index] = '\0'; //terminate the string
  reverse(hex); //we built the string backwards. oops.
  return hex; //voila
}
