#include<stdio.h>
#include <stdlib.h>

struct Student{
    char username[50];
    int marks;


};
void userinput();
void displayinput(struct Student Std[], int a, float avg);

void userinput(){
    struct Student *students;
    int a, sum = 0;
    float avg;
    printf("\nPlease Enter Number Of Students : ");
    scanf("%d", &a);

    students = (struct Student*) malloc(a * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    for (int i = 0; i < a; i++){
        printf("\nPlease Enter The Name Of the Student : ");
        scanf("%s", students[i].username);
        printf("Please Enter The Mark Of the Student : ");
        scanf("%d", &students[i].marks);
        printf("\nStudent Details:\n");
        sum += students[i].marks;
        }
    
    avg = (float)sum / a;

    displayinput(students, a,avg);
    
    free(students);
    
}
void displayinput(struct Student Std[], int a, float avg){
    for (int i = 0; i < a; i++) {
            printf("\nStudent %d\nName: %s\nAge: %d\n", i + 1, Std[i].username, Std[i].marks);
        }
    printf("Avg Marks: %.2f\n", avg);
}

int main(){
    userinput();
    return 0;
}