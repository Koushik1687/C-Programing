#include <stdio.h>

struct employee
{
    int emp_no;
    char emp_name[25];
    int salary;
};

void intake(struct employee *);
void display(struct employee);

void intake(struct employee *e)
{
    printf("Enter the Employee Number: ");
    scanf("%d", &(*e).emp_no);
    printf("Enter the Employee Name: ");
    scanf("%s", (*e).emp_name);
    printf("Enter the Employee Salary: ");
    scanf("%d", &(*e).salary);
};
void display(struct employee e)
{
    printf("Employee ID : %d \n", e.emp_no);
    printf("Employee Name : %s \n", e.emp_name);
    printf("Employee Salary : %d \n", e.salary);
};

int main()
{
    struct employee emp[3];
    int choice, input_saved = 0;
    while (1)
    {
        printf("1 : Taking details,\n2 : Displaying details\nany other number to exit\n\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input_saved = 1;
            for (int i = 0; i < 3; i++)
            {
                printf("\nEmployee %d\n", i + 1);
                intake(&emp[i]);
            }
            printf("\nEmployee details took successfully!!\n\n");
            break;
        case 2:
            if (input_saved)
            {
                printf("Outputs are: \n");
                for (int i = 0; i < 3; i++)
                {
                    printf("Employee %d : \n", i + 1);
                    display(emp[i]);
                    printf("\n");
                }
            }
            else
            {
                printf("\nNo data saved. Please fill out the details first !!\n\n");
            }
            break;
        default:
            printf("\nProgram Exited!!\n");
            exit(0);
        }
    }
    return 0;
}
