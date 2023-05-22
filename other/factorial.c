#include <stdio.h>

int factorial(int fact, int num){
    for(int i = 1; i <= num; i++ ) fact *= i;
    return fact;
} 

int main(){
    int num = 3;
    if(num > 0)
        printf("factorial of %d is %d", num, factorial(1, num));
    else   
        printf("negative num");
}