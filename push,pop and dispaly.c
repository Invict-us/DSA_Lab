#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
void push(int item);
void pop();
void display();
int stack[SIZE],top=-1;
void main()
{
int ch,item;
while (1)
{
    printf("enter 1 to push element,2 to pop element,3 to display stack and 4 to exit\n");
    printf("enter your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
case 1:
    printf("enter item to inseret:\n");
    scanf("%d",&item);
    push(item);
    break;
case 2:
    pop();
    break;
case 3:
    display();
    break;
case 4:
    exit(0);
default:
    printf("invalid choice:\n");
    }
}
}
void push(int item)
{
    if (top==SIZE-1)
        printf("stack overflow\n");
    else
    {
        top=top+1;
        stack[top]=item;
        printf("push successful\n");
    }
}
void pop()
{
    if (top==-1)
        printf("stack underflow\n");
    else
    {
        printf("%d",stack[top]);
        top=top-1;
        printf("pop successful\n");
    }
}
void display()
{
 if (top==-1)
        printf("stack underflow\n");
    else
    {
        printf("stack elements are\n");
        for(int i=top;i>0;i--)
        printf("%d\n",stack[i]);
    }
}
