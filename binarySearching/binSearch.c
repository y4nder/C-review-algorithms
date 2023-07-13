#include <stdio.h>

int BinarySearcher(int *a, int start, int end, int key){
    while(start <= end){
        int mid = (start + end)/2;
        if(a[mid] == key) return mid;
        if(a[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main(){
    int arr[] = {1, 4 ,7 ,8 ,10, 22, 33};

    printf("%d", BinarySearcher(arr, 0, sizeof(arr)/sizeof(arr[0]), 10));
}