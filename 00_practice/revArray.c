#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int newArr[6];
    for(int i = 0; i < 6; i++){
        newArr[i] = arr[5-i];
    }
    for(int i = 0; i < 6; i++){
        printf("%d ", newArr[i]);
    }
}