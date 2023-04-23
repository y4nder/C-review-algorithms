#include <stdio.h>

int add(int a, int b){
    return a + b;
}

int main(){
    int a, b, sum;
    do{
        printf("enter two numbers: ");
        printf("\n");
        scanf("%d",&a);
        scanf("%d",&b);

        sum = add(a,b);

        printf("sum is %d", sum);
        printf("\n");

    } while (sum != 0);
    
}