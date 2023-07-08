#include <stdio.h>
#include <string.h>

typedef struct {
    char cityName[100];
    int temp;
}city;

void printArray(city *c);
void sortSelect(city *c);
int findSmallest(int i, city *c);
void swap(city *c, int i, int j);

int main(){
    city cities[3] = {
        {"Manila", 100},
        {"Cebu", 40},
        {"Ozamis", 80},
    };

    printArray(cities);
    printf("sorting...\n");
    sortSelect(cities);
    printArray(cities);

}

void printArray(city *c){
    for(int i = 0; i < 3; i++){
        printf("%s :%d\n", c[i].cityName, c[i].temp);
    }
}

void sortSelect(city *c){
    int smallest;
    for(int i = 0; i < 3; i++){
        smallest = findSmallest(i, c);
        if(c[i].temp != c[smallest].temp);
            swap(c,i,smallest);
    }
}

int findSmallest(int i, city *c){
    int smallest = i;
    for(int index = smallest; index < 3; index++){
        if(c[index].temp < c[smallest].temp) smallest = index;
    }
    return smallest;
}

void swap(city *c, int i, int j){
    city temp = c[j];
    c[j] = c[i];
    c[i] = temp;
}