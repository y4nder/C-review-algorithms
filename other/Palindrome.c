#include <stdio.h>

int IsPalindrome(char *c, int len){
    for(int i = 0; i < (len/2); i++)
        if(c[i] != c[len - i - 1]) return -1;
    return 0;
}

int length(char *s){
    int i = 0;
    for(; s[i] != '\0'; i++);
    return i;
}

int main(){
    char c[] = "level";
    printf("%d\n", length(c));
    printf("%d\n", IsPalindrome(c, length(c)) );
}