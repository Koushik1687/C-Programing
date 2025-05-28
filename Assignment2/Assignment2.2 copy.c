

#include <stdio.h>
#include <stdlib.h>

struct students
{
    char name[20];
    int marks;
};

int main()
{
    struct students *ptr;
    int i, No_of_Records;
    float totalMarks = 0;

    printf("Enter number of records: ");
    scanf("%d", &No_of_Records);
    
    ptr = (struct students *)malloc(No_of_Records * sizeof(struct students));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    for (i = 0; i < No_of_Records; ++i)
    {
        printf("Enter name of the student: ");
        scanf("%s", ptr[i].name);
        printf("Enter marks of the student: ");
        scanf("%d", &ptr[i].marks);
    }

    printf("\nDisplaying Information:\n");
    
    for (i = 0; i < No_of_Records; ++i) {
        
    }

    float averageMarks = totalMarks / No_of_Records;
    printf("The average marks of the students is: %.2f\n", averageMarks);

    // Free allocated memory
    free(ptr);
    
    return 0;
}
