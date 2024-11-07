#include<stdio.h>
#include <stdlib.h>

#define Capacity 10

typedef struct Stack{
    int arr[Capacity];
    int top;
}Stack;

void push(struct Stack *s, int value){
    if(s->top >= Capacity-1){
        printf("Stack is full");
    }
    s->top++;
    s->arr[s->top]=value;
    return;
}
void pop(struct Stack *s){
    if(s->top == -1){
        printf("Stack is empty");
        return;
    }
    s->top--;
}
void peep(struct Stack *s){
    if(s->top == -1){
        printf("Stack is empty");
        return;
    }
        printf("%d", s->arr[s->top]);
}
int main(){
    Stack s;
    s.top=-1;
    int value;
    int choice;
    while (1)
    {
    printf("Enter your choice\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("Enter the value");
        scanf("%d", &value);
        push(&s, value);
        break;
        case 2:
        pop(&s);
        break;
        case 3:
        peep(&s);
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("Invalid input");
            break;
        }
    }
    return 0;
    
}
