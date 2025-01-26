#include <stdio.h>
#include <string.h>
#define MAX 100
//user define data type (student) using structure having member 
typedef struct
{
    int roll;
    char std_name[50];
    int maths_marks;
    int english_marks;
    int rank;
    int total_marks;
} Student;

Student stack[MAX];
int top = -1;

void push(Student s)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    s.total_marks = s.maths_marks + s.english_marks; // Calculate total marks while adding
    stack[++top] = s;
}

void pop()
{
    if (top < 0)
    {
        printf("Stack underflow!\n");
        return;
    }
    printf("Record of student %s with roll %d deleted.\n", stack[top].std_name, stack[top].roll);
    top--;
}

void display()
{
    if (top < 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i <= top; i++)
    {
        printf("Roll: %d, Name: %s, Maths: %d, English: %d, Total: %d, Rank: %d\n",
               stack[i].roll, stack[i].std_name, stack[i].maths_marks, stack[i].english_marks,
               stack[i].total_marks, stack[i].rank);
    }
}

void display_roll_wise()
{
    if (top < 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    Student temp;
    for (int i = 0; i <= top; i++)
    {
        for (int j = i + 1; j <= top; j++)
        {
            if (stack[i].roll > stack[j].roll)
            {
                temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
    display();
}

void display_descending_marks()
{
    if (top < 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    Student temp;
    for (int i = 0; i <= top; i++)
    {
        for (int j = i + 1; j <= top; j++)
        {
            if (stack[i].total_marks < stack[j].total_marks)
            {
                temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
    display();
}

int main()
{
    int choice;
    Student s;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add Student Record\n");
        printf("2. Delete Student Record\n");
        printf("3. Display All Records\n");
        printf("4. Display Records Roll Wise\n");
        printf("5. Display Records by Descending Total Marks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Roll Number: ");
            scanf("%d", &s.roll);
            printf("Enter Name: ");
            scanf("%s", s.std_name);
            printf("Enter Maths Marks: ");
            scanf("%d", &s.maths_marks);
            printf("Enter English Marks: ");
            scanf("%d", &s.english_marks);
            printf("Enter Rank: ");
            scanf("%d", &s.rank);
            push(s);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            display_roll_wise();
            break;

        case 5:
            display_descending_marks();
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
