#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 100
#define EMPTY_STACK '\0'

// Stack storage
char stack[SIZE];
int istack[SIZE];
int itop = -1;
int top = -1;

// Stack functions for char
void push(char item)
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = item;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return EMPTY_STACK;
    }
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

// Stack functions for int
void ipush(int val)
{
    if (itop == SIZE - 1)
    {
        printf("Integer Stack Overflow\n");
        return;
    }
    istack[++itop] = val;
}

int ipop()
{
    if (itop == -1)
    {
        printf("Integer Stack Underflow\n");
        return -1;
    }
    return istack[itop--];
}

// Operator helpers
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

// Evaluate postfix
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
            }
            ipush(result);
        }
    }
    return ipop();
}

int main()
{
    char infix_expr[100];
    char postfix_expr[100];
    int k = 0;

    printf("Enter an infix expression (use single-digit numbers): ");
    scanf("%s", infix_expr);

    // Convert infix to postfix
    k = 0;
    for (int i = 0; infix_expr[i] != '\0'; i++)
    {
        if (isdigit(infix_expr[i]))
            postfix_expr[k++] = infix_expr[i];
        else if (infix_expr[i] == '(')
        {
            push(infix_expr[i]);
        }
        else if (infix_expr[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix_expr[k++] = pop();
            }
            pop();
        }
        else if (is_operator(infix_expr[i]))
        {
            while (!isEmpty() && precedence(infix_expr[i]) <= precedence(peek()))
            {
                postfix_expr[k++] = pop();
            }
            push(infix_expr[i]);
        }
    }
    while (!isEmpty())
    {
        postfix_expr[k++] = pop();
    }
    postfix_expr[k] = '\0';

    printf("Postfix: %s\n", postfix_expr);

    // Evaluate postfix
    int result = evaluate_postfix(postfix_expr);
    printf("Result: %d\n", result);

    return 0;
}
