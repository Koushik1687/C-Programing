#include <stdio.h>

struct Array {
    int id, age;
    char name[50];
};

void userinput(struct Array input[]);
void displayinput(struct Array input[]);
void deleteinput(struct Array input[]);

int main() {
    struct Array input[3];  // Array for 3 people

    while (1) {
        int opt;
        printf("\nPlease choose an option from the list below:");
        printf("\n 1. Insert Details.");
        printf("\n 2. Show Details.");
        printf("\n 3. Delete Details.");
        printf("\n 4. Exit.");
        printf("\nPlease enter the option now: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                userinput(input);  // Call function to input data
                break;
            case 2:
                displayinput(input);  // Call function to display data
                break;
            case 3:
                deleteinput(input);  // Call function to delete data
                break;
            case 4:
                printf("Goodbye!!\n");
                return 0;  // Exit the program
            default:
                printf("Please choose a correct option!!\n");
        }
    }
    return 0;
}

// Function to input data
void userinput(struct Array input[]) {
    for (int i = 0; i < 3; i++) {
        printf("\nEnter ID for person %d: ", i + 1);
        scanf("%d", &input[i].id);
        
        printf("Enter age for person : ");
        scanf("%d", &input[i].age);
        
        printf("Enter name for person : ");
        scanf("%s", input[i].name);
    }
}

// Function to display data
void displayinput(struct Array input[]) {
    for (int i = 0; i < 3; i++) {
        if (input[i].id != 0) {  // Only display if ID is set (non-zero)
            printf("\nPerson %d Details:", i + 1);
            printf("\nID: %d", input[i].id);
            printf("\nAge: %d", input[i].age);
            printf("\nName: %s\n", input[i].name);
        } else {
            printf("\nPerson %d has no data.\n", i + 1);
        }
    }
}

// Function to delete data
void deleteinput(struct Array input[]) {
    int idToDelete;
    printf("Enter the ID of the person you want to delete: ");
    scanf("%d", &idToDelete);

    for (int i = 0; i < 3; i++) {  // Iterate over the array to find the person
        if (input[i].id == idToDelete) {
            input[i].id = 0;  // Reset the ID to 0 (indicating no data)
            input[i].age = 0;
            input[i].name[0] = '\0';  // Clear the name
            printf("Data for person with ID %d has been deleted.\n", idToDelete);
            return;
        }
    }
    printf("ID not found!\n");
}
