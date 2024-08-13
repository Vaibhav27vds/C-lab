#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[20];
    int age;
}Student;

void sort(Student *students, int *n){
    for(int i = 0; i < *n; i++){
        for(int j = i+1; j < *n; j++){
            if(students[i].id > students[j].id){
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for(int i = 0; i < *n; i++){
        printf("Student %d\n", i+1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
    }
}

int main(){
    printf("Enter the number of students");
    int n; 
    scanf("%d", &n);
    Student *students = (Student *)malloc(n * sizeof(Student));
    for(int i = 0; i < n; i++){
        printf("Enter the id of student %d: ", i+1);
        scanf("%d", &students[i].id);
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter the age of student %d: ", i+1);
        scanf("%d", &students[i].age);
    }
    for(int i = 0; i < n; i++){
        printf("Student %d\n", i+1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
    }

    sort(&students, &n);
}