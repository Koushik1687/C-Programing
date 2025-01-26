#include <stdio.h>
struct emp
{
    int id;
    char name[40];
    int salary;
};
struct emp arr[3];
void input(){
    for (int i = 0; i < 3; i++)
    {
        printf("ID :");
        scanf("%d",&arr[i].id);
        printf("name : ");
        scanf("%s",arr[i].name);
        printf("salary :");
        scanf("%d",&arr[i].salary);
    }
}
void display(){
    for (int i = 0; i < 3; i++)
        {
            printf("ID %d\n",arr[i].id);
            printf("name %s\n",arr[i].name);
            printf("salary %d\n",arr[i].salary);
        }
}
int main () {
    input();
    display();
    return 0;
}