#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

struct node* create()
{
    struct node *newnode, *temp, *head = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory not available\n");
            return head;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void sortList()
{
    struct node *temp, *nextnode;
    int t;

    if (head1 == NULL)
    {
        printf("List 1 is empty\n");
        return;
    }

    for (temp = head1; temp != NULL; temp = temp->next)
    {
        for (nextnode = temp->next; nextnode != NULL;
             nextnode = nextnode->next)
        {
            if (temp->data > nextnode->data)
            {
                t = temp->data;
                temp->data = nextnode->data;
                nextnode->data = t;
            }
        }
    }

    printf("List sorted successfully\n");
}

void reverseList()
{
    struct node *prev = NULL, *current = head1, *nextnode;

    if (head1 == NULL)
    {
        printf("List 1 is empty\n");
        return;
    }

    while (current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    head1 = prev;

    printf("List reversed successfully\n");
}

void concatenate()
{
    struct node *temp;

    if (head2 == NULL)
    {
        printf("List 2 is empty\n");
        return;
    }

    if (head1 == NULL)
    {
        head1 = head2;
    }
    else
    {
        temp = head1;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = head2;
    }

    head2 = NULL;

    printf("Lists concatenated successfully\n");
}

int main()
{
    int choice;

    printf("Hruthya C V\t1WA25CS097\t17/11/2026\n");

    while (1)
    {
        printf("\n1. Create List 1");
        printf("\n2. Create List 2");
        printf("\n3. Sort List 1");
        printf("\n4. Reverse List 1");
        printf("\n5. Concatenate Lists");
        printf("\n6. Display List 1");
        printf("\n7. Display List 2");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head1 = create();
                break;

            case 2:
                head2 = create();
                break;

            case 3:
                sortList();
                break;

            case 4:
                reverseList();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                display(head1);
                break;

            case 7:
                display(head2);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
