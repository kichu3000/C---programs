#include <stdio.h>

#define SIZE 5

void enqueue(int);
int dequeue(int *);
void display();
int queue[SIZE];
int front = -1, rear = -1;

int main()
{

    int choice, value, item;

    while (1)
    {
        printf("\n**********************");
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            if (dequeue(&item))
            {
                printf("Deleted value is %d\n", item);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("The queue is full");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        queue[++rear] = value;
    }
}

int dequeue(int *item)
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        *item = queue[front++];
        if (front > rear)
        {
            front = rear = -1;
        }
        return 1;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (size_t i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}