#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

char stack[SIZE];
int istack[SIZE];
int itop = -1;
int top = -1;

void push(char item)
{
    if (isFull())
    {
        printf("Stack overflows.\n");
        return;
    }
    stack[++top] = item;
}
char pop()
{
    if (isEmpty())
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

// return true if stack is empty.
int isEmpty()
{
    return top == -1;
}
// returns true if stack is full
int isFull()
{
    return top == SIZE - 1;
}

// for integer values

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

int ipeek()
{
    return istack[itop];
}

int iisEmpty()
{
    return itop == -1;
}

int iisFull()
{
    return itop == SIZE - 1;
}
