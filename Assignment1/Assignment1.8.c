#include<stdio.h>

struct students
{
    int roll_no, age;
    float avg;
    char name[50], address[100];
};

void displayinput(struct students records[12]) {
    
    printf("\nHere's are the 12 Students Details Below:");
    
    for (int i = 0; i < 12; i++) { 
        
        printf("\nYour Name: %s", records[i].name);
        printf("\n%s's Roll Number: %d", records[i].name, records[i].roll_no);
        printf("\n%s's Age: %d", records[i].name, records[i].age);
        printf("\n%s's Address: %s", records[i].name, records[i].address); 
        printf("\n%s's Average Marks in Exam: %.2f\n", records[i].name, records[i].avg);
    }
}

void userinput(){
    
    struct students records[12];
    
    printf("\nEnter 12 Students Details Below");
    
    for (int i = 0; i < 12; i++) { 
        
        printf("\nEnter Your Name: ");
        scanf("%s", records[i].name); 

        printf("\nEnter Roll Number: ");
        scanf("%d", &records[i].roll_no); 

        printf("\nEnter Your Age: ");
        scanf("%d", &records[i].age); 
        
        printf("\nEnter Your Address: ");
        scanf("%s", records[i].address); 
        
        printf("\nEnter Your Average Marks: ");
        scanf("%f", &records[i].avg); 
    }
    printf("\n");
    displayinput(records); 
}



int main() {
    userinput();
    return 0;
}
