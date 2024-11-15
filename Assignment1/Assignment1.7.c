#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;


Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}


Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}


void display(Complex c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}

int main() {
    Complex num1, num2, sum, diff;

    printf("Enter first complex number (real and imaginary): ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter second complex number (real and imaginary): ");
    scanf("%f %f", &num2.real, &num2.imag);

    sum = add(num1, num2);
    diff = subtract(num1, num2);

    printf("Sum: ");
    display(sum);
    
    printf("Difference: ");
    display(diff);

    return 0;
}
