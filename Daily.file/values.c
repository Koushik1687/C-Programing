#include<stdio.h>
int add(int a){
    a = 0;
    printf("After : %d\n", a);
}
int add1(int *a){
    *a = 70;
    printf("After : %d\n", *a);
}

float add2(float a){
    printf("After : %f\n", a);
}
int main (){
    
    int a = 10;
    float ab = 10.6;
    printf("Before : %d\n", a);

    add(a);
    add1(&a);
    add2(ab);
}