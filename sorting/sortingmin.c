#include <stdio.h>

void swap(int *n, int i, int j);

void sort(int *n, int len){
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(n[j] < n[i]) swap(n, i, j);
        }
    }
}

void swap(int *n, int i, int j){
    int temp = n[i];
    n[i] = n[j];
    n[j] = temp;
}

int main(){
    int n[] = {12, 52, 74, 1, 65};
    int len = sizeof(n)/sizeof(n[0] );
    sort(n, len);
    for(int i = 0; i < len; i++){
        printf("%d ", n[i]);
    }
}