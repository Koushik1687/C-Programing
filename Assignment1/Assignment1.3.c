#include<stdio.h>
#include<string.h>

struct student 
{
    char name[20];
    int roll;
    int marks;
};

int main(){
    struct student s1 = {"Koushik",2004,95};
    struct student *ptr;
    ptr = &s1;
    puts("Student Details: ");
    printf("Name : %s\n",ptr->name);
    printf("Roll : %d\n",ptr->roll);
    printf("Marks : %d\n",ptr->marks);
    return 0;
}
