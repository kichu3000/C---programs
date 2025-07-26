#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

void infix_to_postfix(char str[]);
int precedence(char ch);
int is_operator(char ch);
int main()
{
    char expr[100];

    printf("Enter an infix expression: ");
    scanf("%s", expr);

    infix_to_postfix(expr);
    printf("\n");

    return 0;
}

void infix_to_postfix(char str[])
{
    char result[100];
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
            result[k++] = str[i];
        else if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                result[k++] = pop();
            }
            pop();
        }
        else if (is_operator(str[i]))
        {
            while (!isEmpty() && precedence(str[i]) <= precedence(peek()))
            {
                result[k++] = pop();
            }
            push(str[i]);
        }
    }
    while (!isEmpty())
    {
        result[k++] = pop();
    }
    result[k] = '\0';

    printf("The postfix expression is:");
    for (int i = 0; i < strlen(result); i++)
    {
        printf("%c", result[i]);
    }
}

int is_operator(char ch)
{
    return ch == '*' || ch == '-' || ch == '+' || ch == '/' || ch == '^';
}

int precedence(char ch)
{

    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}