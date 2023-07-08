#include <stdio.h>

int Smallest(int *n, int start, int length);
void Swap(int *n, int a, int b);

void Sort(int *n, int length){
    int smallest;
    for(int i = 0; i < length; i++){
        smallest = Smallest(n, i, length);
        if(n[i] != n[smallest])
            Swap(n, i, smallest);
    }
}

int Smallest(int *n, int start, int length){
    int smallest = start;
    for(int i = start + 1; i < length; i++){
        if(n[i] < n[smallest] ) smallest = i;
    }   
    return smallest;
}

void Swap(int *n, int a, int b){
    int c;
    c = n[a];
    n[a] = n[b];
    n[b] = c;
}

int main(){
    int n[] = {12, 52, 74, 1, 65};
    int len = sizeof(n)/sizeof(n[0] );
    Sort(n, len);
    for(int i = 0; i < len; i++) printf("%d ", n[i]);
}