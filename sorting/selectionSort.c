#include <stdio.h>
#include <stdlib.h>

void selectionSorter(int *a, int min, int max, int option);
void swap(int *a, int *b);
void displayArray(int *a, int limit);

int main(){
    int limit, *arr = NULL, option; 

    //input limit of array
    printf("Enter limit of array: ");
    scanf("%d",&limit);
    arr = (int*)malloc(limit * sizeof(int));

    //store values into array
    printf("\nEnter array\n");
    for(int i = 0; i < limit; i++)
        scanf("%d", &arr[i]);

    printf("Asending order   -- 1\n");
    printf("Descending order -- 2\n");
    printf("option: ");
    scanf("%d", &option);

    //sort the array
    selectionSorter(arr, 0, limit, option);

    //print the sorted array
    printf("\nSorted Array\n");
    displayArray(arr, limit);
    
    return 0;
}


//functions
void selectionSorter(int *a, int min, int max, int option){
    for(int i = min; i < max; i++){
        for(int j = i + 1; j < max; j++){
            if(option == 1){
                if(a[i] > a[j])
                    swap(&a[i], &a[j]);
            }
            else{
                if(a[i] < a[j])
                    swap(&a[i], &a[j]);
            }
        }
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void displayArray(int *a, int limit){
    for(int i = 0; i < limit; i++){
        printf("%d ",a[i]);
    }
}