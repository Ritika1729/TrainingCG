#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    int (*operation)(int, int);

    int num1, num2;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%d", &num2);

   
    switch (operator) {
        case '+':
            operation = add;
            break;
        case '-':
            operation = subtract;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            if (num2 != 0) {
                operation = divide;
            } else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        default:
            printf("Error: Unknown operator!\n");
            return 1;
    }

    int result = operation(num1, num2);
    printf("Result: %d\n", result);

    return 0;
}
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b; 
}

