#include <stdio.h>
#include <stdlib.h>

int getLimit();
int linearSearch(int *a, int key, int min, int max);
void displayResult(int pos);

int main(){
    int num, key, pos; 
    int *arr = NULL;

    //size of array
    num = getLimit();
    arr = (int*)malloc(num * sizeof(int));

    //input elements of array
    for(int i = 0; i < num; i++){
        printf("Enter number #%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    //look for key
    printf("Enter key: ");
    scanf("%d", &key);

    //call function
    pos = linearSearch(arr, key, 0, num);

    //determine if key is found 
    displayResult(pos);
}

int linearSearch(int *a, int key, int min, int max){
    for(int i = min; i <= max; i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}

int getLimit(){
    int limit;
    printf("How many numbers?: ");
    scanf("%d",&limit); 
    return limit;
}

void displayResult(int pos){
    if(pos == -1)
        printf("key not found.");
    else
        printf("key found at position %d", pos + 1);
}
