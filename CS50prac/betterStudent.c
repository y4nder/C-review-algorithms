#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct{
    char name[20];
    float gpa;
    int grade;
}Student;

typedef struct{
    Student list[MAX];
    int counter;
    char sectionName[20];
}Class;

typedef struct{
    Class sectionList[MAX];
    int counter;
    int yearLevel;
}Year;



void displayClass(Class x);
void createSection(Class *x, char n[]);
void addStudent(Class *x, char n[], float fG, int g);

void sortStudents(Class *x);
int findFirst(Class *x, int index);
void swap(Class *x, int i, int j);

void createYearLevel(Year *y, int lvl);
void addClass(Year *y, Class x);
void displayYear(Year y);
void sortClasses(Year *y);
int findFirstC(Year *x, int index);
void swapC(Year *x, int i, int j);
void removeLastStudent(Class *x);
void removeFirstStudent(Class *x);
void removeStudentAt(Class *x, int index);
void addStudentAt(Class *x, int index, char n[], float fG, int g);



int main(){
    Class a;
    createSection(&a, "St.Mark");
    addStudent(&a, "Leander", 2.5, 89);
    addStudent(&a, "John", 1.3, 90);
    addStudent(&a, "Margaret", 2.2, 85);
    //displayClass(a);

    Class b;
    createSection(&b, "St.Paul");
    addStudent(&b, "Mark", 1.2, 96);
    addStudent(&b, "Dave", 1.6, 87);
    addStudent(&b, "Jonathan", 2.2, 90);

    Class c;
    createSection(&c, "St.Andrew");
    addStudent(&c, "Jake", 2.1, 87);
    addStudent(&c, "Hannah", 1.1, 97);
    addStudent(&c, "Dave", 2.6, 84);
    addStudent(&c, "Yassi", 3.1, 89);
    addStudent(&c, "Paige", 2.2, 83);

    Year year1;
    createYearLevel(&year1, 10);
    addClass(&year1, a);
    addClass(&year1, b);

    Year year2;
    createYearLevel(&year2, 11);
    Class x,y;
    createSection(&x,"St.Bernadette");
    createSection(&y,"St.Therese");
    addClass(&year2, x);
    addClass(&year2, y);
    addClass(&year2, c);


    //displayYear(year1);
    //displayYear(year2);
    //sortClasses(&year2);
    //displayYear(year2);
    //displayClass(a);
    displayClass(x);
    addStudentAt(&x, 2, "Michael", 1.3, 99);
    displayClass(x);

}

void createSection(Class *x, char n[]){
    x->counter = 0;
    strcpy(x->sectionName, n);
}

void addStudent(Class *x, char n[], float fG, int g){
    if(x->counter < MAX){
        x->counter++;
        strcpy(x->list[x->counter-1].name,n);
        x->list[x->counter-1].gpa = fG;
        x->list[x->counter-1].grade = g;
    }
    else {
        printf("\nStudent slot is full\n"); printf("%s was not enrolled\n", n);
    }
}

void addStudentAt(Class *x, int index, char n[], float fG, int g){
    if(x->counter < MAX && (index > 0 && index < x->counter)){
        x->counter++;
        for(int i = index-1; i < x->counter-1; i++){
            x->list[i+1] = x->list[i];
        }
        strcpy(x->list[index].name,n);
        x->list[index].gpa = fG;
        x->list[index].grade = g;
        printf("%s was added to section %s at index %d\n", n, x->sectionName, index+1);
    }
    else printf("\n%s was not enrolled\n", n);
}

void removeLastStudent(Class *x){
    if(x->counter > 0){
        x->counter--;
        printf("%s was removed from section %s\n",x->list[x->counter].name, x->sectionName );
    }
    else printf("no students to remove in section %s", x->sectionName);
}

void removeFirstStudent(Class *x){
    if(x->counter > 0){
        printf("%s was removed from section %s\n",x->list[0].name, x->sectionName );
        for(int i = 0; i < x->counter-1; i++){
            x->list[i] = x->list[i+1];
        }
        x->counter--;
    }
    else printf("no students to remove in section %s", x->sectionName);
}

void removeStudentAt(Class *x, int index){
    if(index < x->counter && index > 0){
        printf("%s was removed from section %s\n",x->list[index-1].name, x->sectionName );
        for(int i = index-1; i < x->counter-1; i++){
            x->list[i] = x->list[i+1];
        }
    }
    else printf("INVALID INDEX to remove\n");
}

void createYearLevel(Year *y, int lvl){
    y->counter = 0;
    y->yearLevel = lvl;
}

void addClass(Year *y, Class x){
    y->counter++;
    y->sectionList[y->counter-1] = x;
}

void displayClass(Class x){
    if(x.counter > 0){
        printf("\nDisplaying section %s\n", x.sectionName);
        for(int i = 0; i < x.counter; i++){
            printf("%s : %.01f -- %d\n", x.list[i].name, x.list[i].gpa, x.list[i].grade);
        }
    }
    else printf("No students are enrolled in section %s", x.sectionName);
}

void displayYear(Year y){
    if(y.counter > 0){
        printf("\nSections in Year %d\n", y.yearLevel);
        for(int i = 0; i < y.counter; i++){
            printf("%d.) %s\n", (i+1), y.sectionList[i].sectionName);
        }
    }
    else printf("No sections in year level %d\n", y.yearLevel);
}

//sorting algorithms
void sortStudents(Class *x){
    for(int i = 0 ; i < x->counter; i++){
        int first = findFirst(x, i);
        swap(x, i, first);
    }
}
void sortClasses(Year *y){
    for(int i = 0 ; i < y->counter; i++){
        int first = findFirstC(y, i);
        swapC(y, i, first);
    }
}

int findFirst(Class *x, int index){
    int first = index;
    for(int i = first; i < x->counter; i++){
        if(x->list[i].gpa > x->list[first].gpa) first = i;
    }
    return first;
}

int findFirstC(Year *x, int index){
    int first = index;
    for(int i = first; i < x->counter; i++){
        if(strcmp(x->sectionList[i].sectionName, x->sectionList[first].sectionName) < 0) first = i;
    }
    return first;
}

void swap(Class *x, int i, int j){
    Student temp = x->list[i];
    x->list[i] = x->list[j];
    x->list[j] = temp;
}

void swapC(Year *x, int i, int j){
    Class temp = x->sectionList[i];
    x->sectionList[i] = x->sectionList[j];
    x->sectionList[j] = temp;
}

