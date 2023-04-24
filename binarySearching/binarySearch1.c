#include <stdio.h>
#include <stdlib.h>

int binarySearch(int key, int *a, int min, int max){
    int mid, count = 0;
    while(min <= max){
        mid = (min + max)/2;
        if(a[mid] == key){
            return mid;
        }
        else if(a[mid] < key){
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }
    return -1;
}

int main(){
    int limit, *arr = NULL, key, pos;

    printf("limit: ");
    scanf("%d", &limit);
    arr = (int*)malloc(limit * sizeof(int));

    for(int i = 0; i < limit; i++){
        scanf("%d", &arr[i]);
    }

    printf("key: ");
    scanf("%d", &key);

    pos = binarySearch(key, arr, 0, limit);

    if(pos == -1)
        printf("not found");
    else
        printf("found at index %d", pos + 1);
    return 0;
}