#include <stdio.h>

int linearSearch(int *n, int l, int x){
    for(int i = 0; i < l; i++)
        if(x == n[i]) return i + 1;
    return -1;
}

int main(){
    int n[] = {1, 2, 3, 4, 5};
    printf("%d",linearSearch(n, sizeof(n)/sizeof(int)-1, 3));
}