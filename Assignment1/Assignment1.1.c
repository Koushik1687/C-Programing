#include <stdio.h>
struct distance
{
    int inch, feet;
};

void userinput() {
    struct distance in1, in2;
    printf("\nThis is a Distance Calculator\n");
    
    printf("\nPlease Enter Feet : ");
    scanf("%d",&in1.feet);
    
    printf("Please Enter Inch : ");
    scanf("%d",&in1.inch);
    

    printf("\nNow enter the distance you want to add\n");
    
    printf("\nPlease Enter Feet : ");
    scanf("%d",&in2.feet);
    
    printf("Please Enter Inch : ");
    scanf("%d",&in2.inch);
    

    calculation(in1,in2);

}

void calculation(struct distance in1,struct distance in2){
    
    struct distance result;

    result.feet = in1.feet + in2.feet;
    result.inch = in1.inch + in2.inch;

    if (result.inch >=12){
        result.feet += result.inch/12;
        result.inch = result.inch%12;
    }
    displayoutput(result);
}

void displayoutput(struct distance result)
{
    printf("\nThe Total Number of Distance is : \n");
    printf("\nFoot : %d \n",result.feet);
    printf("Inch : %d \n",result.inch);
}


int main() {
    userinput();
    return 0;
}

