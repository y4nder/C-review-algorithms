#include <stdio.h>

int maxTotalAtSubArr(int a[], int k, int length){
    int arrLength = length;
    int total = 0, maxTotal;

    for(int i = 0; i < k; i++){
        total += a[i];
    }

    maxTotal = total;

    for(int i = 1; i < arrLength - k + 1; i++){
        total -= a[i-1];
        total += a[i+k-1];

        if(total > maxTotal) maxTotal = total;
    }
    
    return maxTotal;
}

int main(){
    int arr[] = {1, 2, 3, 4, 2, 6, 2, 2, -2, 3};
    int k = 3;
    
    printf("%d", maxTotalAtSubArr(arr,k, 10));
}