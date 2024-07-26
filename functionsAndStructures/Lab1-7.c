#include<stdio.h>

typedef struct{
    char name[50];
    int age;
    int totalMarks;
} Student;

int main(){
    Student s1,s2;
    int n;
        printf("Enter the name of student 1: \n ");
        scanf("%s",&s1.name);
        printf("Enter the age of student 1: \n");
        scanf("%d",&s1.age);
        printf("Enter the total marks of student 1: \n");
        scanf("%d",&s1.totalMarks);
         printf("Enter the name of student 2: \n ");
        scanf("%s",&s2.name);
        printf("Enter the age of student 2: \n");
        scanf("%d",&s2.age);
        printf("Enter the total marks of student 2: \n");
        scanf("%d",&s2.totalMarks);
        int result = s1.totalMarks + s2.totalMarks;
        printf("The total marks of student 1 and student 2 is: %d",result);
    return 0;
}