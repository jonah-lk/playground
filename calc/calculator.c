#include <stdlib.h>
#include <stdio.h>
#include <float.h>

int main() {
    char operation, exit;
    double num1, num2, result;

    while (1) {
        system("cls");

        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operation);
    
        printf("Enter two operands: \n");
        printf("First operand: ");
        scanf(" %lf", &num1);
        printf("Second operand: ");
        scanf(" %lf", &num2);
        
        switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
             result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Error! Incorrect Operator Value\n");
            result = -DBL_MAX;
        }
    
        if(result != -DBL_MAX)
          printf(" %.2lf", result);
    
        printf("\nPress x to exit or anything else to do another opration!\n");
        scanf(" %c", &exit);

        if(exit == 'x')
            break;
    }
    
    return 0;
}
