#include <stdio.h>

int isPrime(int x);
void display(int x, int i);

int isPrime(int x){
    for(int i = 2; i < x ; i++ ){
        if(x % i == 0) return 0;
    }
    return 1;
}

void searchPrime(int *n, int length){
    int prime = 1;
    for(int i = 0; i < length; i++){
        prime = isPrime(n[i]);
        if(prime == 1)
            display(n[i], i);
    }
}

void display(int x, int i){
    printf("%d at index %d is prime\n",x, i );
}

int main(){
    int n[] = {1, 2, 3, 4, 5, 13, 6, 7, 8, 9};
    int len = sizeof(n)/sizeof(n[0]);
    searchPrime(n, len);
}