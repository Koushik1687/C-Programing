#include<stdio.h>
#include<math.h>

typedef struct cartesian_point
{
    float a,b;
}Cpoint;

double distance(Cpoint C1, Cpoint C2){
    return sqrt(pow((C2.a - C1.a),2) + pow((C2.b - C1.b),2));
}

int main(){
    Cpoint x,y;
    printf("Enter coordinates of the first point, (x,y): ");
    scanf("%f %f", &x.a,&x.b);
    printf("Enter coordinates of the second point, (x,y): ");
    scanf("%f %f", &y.a,&y.b);
    printf("Distance : %.2f",distance(x,y));
    return 0;
}
