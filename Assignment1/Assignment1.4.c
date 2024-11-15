#include <stdio.h>
struct Person{
    char Name[20], Phoneno[10];
    int Age;
};
void displayPerson(struct Person records);
void inputPerson(){

    struct Person records;

    printf("Enter Your Name : ");
    scanf("%s",records.Name);

    printf("Enter Your Phone Number : ");
    scanf("%s",records.Phoneno);
    
    printf("Enter Your Age : ");
    scanf("%d",&records.Age);
    
    printf("\n");
    
    displayPerson(records);
}

void displayPerson(struct Person records){
    printf("Your Name is : %s\n",records.Name);
    
    printf("%s's Phone Number : %s\n",records.Name, records.Phoneno);
    
    printf("%s's Age : %d\n",records.Name,records.Age);
}

int main(){
    
    inputPerson();
    
    return 0;
}


