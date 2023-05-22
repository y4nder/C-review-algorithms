#include <stdio.h>

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 9; j > 0; j--){
            if(j > (i/2) + 1) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
}