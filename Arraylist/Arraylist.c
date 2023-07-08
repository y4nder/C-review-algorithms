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
    else printf("nothing to print\n");
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

void AddnumPos(Arraylist *a, int num, int pos){
    if( (pos + 1) < MAX){
        if( pos > a->counter){
            for(int i = a->counter + 1; i < pos; i++){
                a->list[i] = 0;
            }
            
            a->list[pos] = num;
        }

        else{
            for(int i = a->counter - 1 ; i > pos - 1; i-- ){
                a->list[i] = a->list[i + 1];
            }
        }
        a->counter++;

    }
}

int main(){
    Arraylist a;
    initArray(&a);
    int x, num, pos;

    do
    {
        printf("options: \n");
        printf("1: add to array \n");
        printf("2: delete first element\n");
        printf("3: delete last element\n");
        printf("4: delete entire array\n");
        printf("5: add at position\n");
        printf("6: exit\n");
        printf("choose: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1: 
            printf("enter num to add: ");
            scanf("%d", &num);
            Addnum(&a, num);
            break;
        
        case 2:
            DelFirst(&a);
            break;

        case 3: 
            DelLast(&a);
            break;

        case 4:
            DelArr(&a);
            break;
        
        case 5:
            printf("enter num to add: ");
            scanf("%d", &num);
            printf("enter position: ");
            scanf("%d", &pos);
            AddnumPos(&a, num, pos - 1);
            break;
        }
        
        if(x != 6){
            printf("\n");
            displayArray(a);
            printf("\n\n");
        }

    } while (x != 6);
    
}
