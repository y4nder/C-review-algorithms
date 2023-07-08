#include <stdio.h>

void QuickSort(int *n, int min, int max);
void swap(int *n, int a, int b);

int partition(int *n, int min, int max){
    int pivot = min;
    int i = min + 1;
    int j = max - 1;

    while(1){
        while(n[i] <= n[pivot] && i <= max)
            i++;
        
        while(n[j] > n[pivot])
            j--;

        if( i < j)
            swap(n, i, j);
        else {
            swap(n, pivot, j);
            return j;
        }

    }

}

void QuickSort(int *n, int min, int max){
    int j;
    if(min < max ){
        j = partition(n, min, max);
        QuickSort(n, min, j - 1);
        QuickSort(n, j + 1, max);
    }
}

void swap(int *n, int a, int b){
    int c = n[a];
    n[a] = n[b];
    n[b] = c;
}

int main(){
    int n[] = { 1, 5, 74, 9, 95, 47, 35, 14};
    int len = sizeof(n)/sizeof(n[0]);
    QuickSort(n, 0, len);

    for(int i = 0; i < len; i++) printf("%d ", n[i]);
}