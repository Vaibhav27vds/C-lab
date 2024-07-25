// Write a program to create a structure to store the information of n number of
// Employees. Employee’s information includes data members: Emp-id, Name,
// Designation, basic_salary, hra%, da%. Display the information of employees with
// gross salary. Use array of structure.

#include<stdio.h>

struct Employees{
    int id;
    char name[20];
    char designation[20];
    float basic_salary;
    float hra;
    float da;
}employee;

int main(){
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employees employee[n];
    for(int i=0; i<n; i++){
        printf("Enter the id of employee %d: ", i+1);   
        scanf("%d", &employee[i].id);   
        printf("Enter the name of employee %d: ", i+1);
        scanf("%s", &employee[i].name);
        printf("Enter the designation of employee %d: ", i+1);
        scanf("%s", &employee[i].designation);
        printf("Enter the basic salary of employee %d: ", i+1);
        scanf("%f", &employee[i].basic_salary);
        printf("Enter the hra of employee %d: ", i+1);
        scanf("%f", &employee[i].hra);
        printf("Enter the da of employee %d: ", i+1);
        scanf("%f", &employee[i].da);
        }
        for(int i=0; i<n; i++){
            employee[i].hra = employee[i].basic_salary * 0.2;
            employee[i].da = employee[i].basic_salary * 0.3;
            employee[i].basic_salary = employee[i].basic_salary + employee[i].hra + employee[i].da;
            printf("The gross salary of employee %d is: %.2f \n", i+1, 
            employee[i].basic_salary);
            }
            return 0;
            
}