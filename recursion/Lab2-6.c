//Write a C program to add two distances(feet-inch system) entered by user. To solve this
//program,make a structure. Pass two structure variable (containing distance in feet and inch) to
//add() function by reference and display the result in main function without returning it.

#include<stdio.h>

typedef struct{
    int feet;
    int inch;
} distance;

void addDistances(distance *a, distance *b){
    a->feet +=  b->feet;
    a->inch +=  b->inch;
    if(a->inch >= 12){
        a->inch = a->inch % 12;
        a->feet = a->feet + 1;
    }

    printf("The sum of the distances is %d ft %d inchs", a->feet, a->inch );
}

int main (){
    distance d1,d2;
    printf("Enter the first distance in feet and inch: ");
    scanf("%d %d",&d1.feet,&d1.inch);
    printf("Enter the second distance in feet and inch: ");
    scanf("%d %d",&d2.feet,&d2.inch);
    addDistances(&d1,&d2);
    return 0;

}