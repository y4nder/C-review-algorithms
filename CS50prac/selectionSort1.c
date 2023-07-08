#include <stdio.h>

void display(int *a, int size);
void selectionSorter(int *a, int size);
int findSmallest(int *a, int index, int size);
void swap(int *a, int i, int j);

int main(){
    int arr[] = {6, 8, 4, 2, 0, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    printf("\nsorted arr...\n");
    selectionSorter(arr,size);
    display(arr,size);
}

void display(int *a, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",a[i]);
    }
}

void selectionSorter(int *a, int size){
    int smallest;
    for(int i = 0; i < size; i++){
        smallest = findSmallest(a, i, size);
        swap(a, i, smallest);
    }
}

int findSmallest(int *a, int index, int size){
    int smallest = index;
    for(int i = index; i < size; i++){
        if(a[i] < a[smallest]) smallest = i;
    }
    return smallest;
}

void swap(int *a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}