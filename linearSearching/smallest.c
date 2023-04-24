//{12, 52, 74, 1, 65}
#include <stdio.h>

int smallest(int *n, int length){
    int small = n[0];
    for(int i = 1; i < length; i++){
        if(n[i] < small)
            small = n[i];
    }
    return small;
}

int main(){
    int n[]= {12, 52, 74, 15, 65};
    printf("smallest is %d", smallest(n, sizeof(n)/sizeof(n[0])));
}