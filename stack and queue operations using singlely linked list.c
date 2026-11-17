#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

/* STACK OPERATIONS */

void push()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("Popped element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void displayStack()
{
    struct node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* QUEUE OPERATIONS */

void insert()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void delete()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice;

    printf("Hruthya C V\t1WA25CS097\t17/11/2026\n");

    while (1)
    {
        printf("\n--- STACK OPERATIONS ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display Stack");

        printf("\n--- QUEUE OPERATIONS ---");
        printf("\n4. Insert");
        printf("\n5. Delete");
        printf("\n6. Display Queue");

        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: insert(); break;
            case 5: delete(); break;
            case 6: displayQueue(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
