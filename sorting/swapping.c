#include <stdio.h>

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int a = 5;
    int b = 4;
    printf("a = %d b = %d", a, b);

    swap(&a, &b);

    printf("\na = %d b = %d", a, b);

}