#include <stdio.h>

int BinarySearcher(int *n, int len, int x){
    int mid;
    int i = 0;
    while( i <= len){ 
        mid = (i+len)/2;
        if(n[mid] == x) return mid; 
        if(x > n[mid])  i = mid + 1;
        else len = mid - 1;
    }
    return -1;
}

int main(){
    int n[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%d", BinarySearcher(n, (sizeof(n)/sizeof(n[0]) - 1), 2) );
}