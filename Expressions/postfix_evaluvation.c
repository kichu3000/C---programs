#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
int evaluate_postfix(char expr[]);

int main()
{
    char expr[100];

    printf("Enter a postfix expression: ");
    scanf("%s", expr);

    int result = evaluate_postfix(expr);
    printf("Result: %d\n", result);

    return 0;
}

int evaluate_postfix(char expr[])
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (isdigit(expr[i]))
        {
            ipush(expr[i] - '0');
        }
        else
        {
            int op1 = ipop();
            int op2 = ipop();
            int result;
            switch (expr[i])
            {
            case '+':
                result = op2 + op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                result = op2 / op1;
                break;
            default:
                printf("Invalid operator %c\n", expr[i]);
                return -1;
                break;
            }
            ipush(result);
        }
    }
    return ipop();
}