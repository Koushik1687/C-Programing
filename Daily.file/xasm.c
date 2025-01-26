#include<stdio.h>

struct Array {
    int id, age;
    char name[50];
};

// Corrected function declaration
void userinput(struct Array input[]);

void userinput(struct Array input[]) {
    // Remove redefinition of input (struct Array input;)
    
    for(int i = 0; i < 5; i++) {
        printf("Enter ID for person %d: ", i + 1);
        scanf("%d", &input[i].id);  // Use & to pass the address of input[i].id
        
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &input[i].age); // Use & to pass the address of input[i].age
        
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", input[i].name); // No need for & with strings
    }
}

int main() {
    struct Array arr[5];  // Declare an array of struct Array with size 5
    userinput(arr);       // Pass the array to the function
    return 0;
}