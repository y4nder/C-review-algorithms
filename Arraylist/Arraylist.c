#include <stdio.h>
#include <stdlib.h>

#define MAX 15

typedef struct Arraylist{
    int list[MAX];
    int counter;
} Arraylist; 

void initArray(Arraylist *a){
    a->counter = 0;
}

void displayArray(Arraylist a){
    if(a.counter > 0){
        printf("Displaying list\n");
        for(int i = 0; i < a.counter; i++)
            printf("%d ", a.list[i]);
    }
    else printf("nothing to print");
}

void Addnum(Arraylist *a, int num){
    if(a->counter == MAX) {
        printf("full list, unable to add %d to the list \n", num);
    }
    else{
        printf("Adding %d to the list...\n", num);
        a->list[a->counter] = num;
        a->counter++;
    }
}

void DelLast(Arraylist *a){
    printf("deleting %d from the list\n", a->list[a->counter-1]);
    a->counter--;
}

void DelFirst(Arraylist *a){
    printf("deleting %d from the list\n", a->list[0]);
    for(int i = 0; i < a->counter - 1; i++)
        a->list[0 + i] = a->list[1+i];
    a->counter--;
}

void DelArr(Arraylist *a){
    printf("deleting entire list\n");
    a->counter = 0;
}

int main(){
    Arraylist a;
    initArray(&a);
    Addnum(&a, 3);
    Addnum(&a, 2);
    Addnum(&a, 2);
    Addnum(&a, 19);

    displayArray(a);
    printf("\n");

    DelArr(&a);
    displayArray(a);
    printf("\n");

    Addnum(&a, 2);
    Addnum(&a, 19);

    displayArray(a);
    printf("\n");

}
