#include <stdio.h>
#include <stdlib.h>

int linearSearcher(int limit, int key, int *arr){
    int count = 0;
    int found = 0;
    for(int i = 0; i <= limit; i++){
        if(arr[i] == key){
            printf("key found at index %d\n", i+1);   
            found++;
        }
        count++;
    }
    printf("looped = %d\n", count);
    return found;
}

int main(){
    int limit, *arr = NULL, key, found;
    do{
        //enter limit of array
        printf("\nEnter limit of array: ");
        scanf("%d", &limit);    
        arr = (int*)malloc(limit * sizeof(int));
        
        //store values into array
        for(int i = 0; i < limit; i++){
            printf("Enter value #%d ", i+1);  
            scanf("%d", &arr[i]);
        }
        
        //enter key
        printf("Enter key to search: ");
        scanf("%d", &key);
        
        //search for key using function
        found = 1;
        found = linearSearcher(limit, key, arr);

        //display result
        if(found == 0)
            printf("key was not found :(\n"); 
        }
        
    while(found == 0);
    
    return 0;
}