// stack.h
#ifndef STACK_H
#define STACK_H

#define SIZE 100
#define EMPTY_STACK '\0'

// char stack
void push(char);
char pop();
char peek();
int isEmpty();
int isFull();

// int stack
void ipush(int);
int ipop();
int ipeek();
int iisEmpty();
int iisFull();
#endif
