//{1, 23, 47, 58, 59, 68, 78, 99, 101}
//find index of 59

#include <stdio.h>

int Search(int *n, int max, int x){
    int min = 0;
    int mid;
    while(min <= max){
        mid = (min + max)/2;
        if(n[mid] == x) return mid;
        else if (n[mid] < x) min = mid + 1;
        else max = mid - 1;
    }
    return -1;
}

int main(){
    int n[] = {1, 23, 47, 58, 59, 68, 78, 99, 101};
    printf("%d", Search(n, (sizeof(n)/sizeof(n[0]) - 1), 101 ) );
}