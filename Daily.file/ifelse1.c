#include <stdio.h>
struct arr
{
    int size;
    int arr[4];
};

void userinput();
void displayuserinput();
void calculation();

int main() {
    userinput();
    return 0;
}

void userinput(){
    struct arr input;
    input.size = 4;
    printf("Please Enter Your All 5 Subjects Marks Below\n");
    for (int i = 0; i < input.size; i++)
    {
        switch (i)
        {
        case 0:
            printf("Please Enter Your Bangali Subject Marks : ");
            break;
        case 1:
            printf("Please Enter Your English Subject Marks : ");
            break;
        case 2:
            printf("Please Enter Your Maths Subject Marks : ");
            break;
        case 3:
            printf("Please Enter Your Computer Subject Marks : ");
            break;
        } 
        scanf("%d",&input.arr[i]);
    }
    displayuserinput(input);
}

void displayuserinput(struct arr input){
    for (int i = 0; i < input.size; i++)
    {
        switch (i)
        {
        case 0:
            printf("Bangali Subject Marks : %d\n",input.arr[i]);
            break;
        case 1:
            printf("English Subject Marks : %d\n",input.arr[i]);
            break;
        case 2:
            printf("Maths Subject Marks : %d\n",input.arr[i]);
            break;
        case 3:
            printf("Computer Subject Marks : %d\n",input.arr[i]);
            break;
        } 
    calculation(input);
    }
}

void calculation(struct arr input){
    float result  = 0;
    for (int i = 0; i < input.size; i++)
    {
        result = input.arr[i]+result;
    }
    printf("Total Marks : %.0f\n", result);
    printf("Your Avarage Marks is : %0.2f\n", result/input.size);
}