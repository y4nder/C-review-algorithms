#include <stdio.h>

int Smallest(int *n, int start, int length);
void swap(int *n, int index2, int index1, int length);

void Sort(int *n, int length){
    for(int i = 0; i < length; i++){
        int iSmall = Smallest(n, i, length);
        if(n[i] != n[iSmall])
            swap(n, iSmall, i, length);
    }
}

int Smallest(int *n, int start, int length){
    int smallest = start;
    for(int i = start + 1; i < length; i++)
        if(n[i] < n[smallest]) smallest = i;
    return smallest;
}

void swap(int *n, int index2, int index1, int length){
    int temp = n[index1];
    n[index1] = n[index2];
    n[index2] = temp;
}

int main(){
    int n[] = {12, 1, 74, 1, 65};
    int len = sizeof(n)/sizeof(n[0]);
    Sort(n, len);

    for(int i = 0; i < len; i++) printf("%d ", n[i]);
}