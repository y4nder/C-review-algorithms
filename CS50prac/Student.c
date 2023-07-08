#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
    char name[20];
    float finalGrade;
    int grade;
}Student;

typedef struct{
    Student list[MAX];
    int counter;
}Class;

void display(Student *s, int size);
void sorter(Student *s, int size);
int findSmallest(Student *s, int size, int index);
void swap(Student *s, int i, int j);

void createList(Class c);

int main(){
    Student section1[5] = {
        {"Mark", 2.5, 88},
        {"James", 1.3, 97},
        {"Peter", 1.9, 83},
        {"Kate", 2.2, 79},
        {"John", 1.2, 86},
    };
    int size = sizeof(section1)/sizeof(section1[0]);
    sorter(section1, size);
    display(section1, size);
    Class a;
    createList(a);
}

void display(Student *s, int size){
    for(int i = 0; i < size; i++){
        printf("%s - %.01f - %d\n", s[i].name, s[i].finalGrade, s[i].grade);
    }
}

void displayClass(Class x){
    for(int i = 0; i < x.counter; i++){
        display(x.list[i],size);
    }
}

void createList(Class c){
    c.counter = 0;
}

void addStudent(Class x, char n[], float fG, int g){
    if(x.counter < MAX){
        x.counter++;
        strcpy(x.list[x.counter-1].name, n);
        x.list[x.counter-1].finalGrade = fG;
        x.list[x.counter-1].grade = g;
    }
}


void sorter(Student *s, int size){
    for(int i = 0; i < size; i++){
        int smallest = findSmallest(s, size, i);
        swap(s, i, smallest);
    }
}

int findSmallest(Student *s, int size, int index){
    int smallest = index;
    for(int i = smallest; i < size; i++){
        //if(s[i].grade < s[smallest].grade) smallest = i;
        if(strcmp(s[i].name, s[smallest].name) < 0 ) smallest = i;
    }
    return smallest;
}

void swap(Student *s, int i, int j){
    Student temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

