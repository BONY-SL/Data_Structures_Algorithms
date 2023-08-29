//
// Created by danid on 8/30/2023.
//
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct{
    int top;
    int ele[MAX];
}Stack;

void init(Stack *s)
{
    s->top = -1;
}

void push(Stack *s,int *item);
int isFull(Stack *s);
int isEmpty(Stack *s);
void pop(Stack *s,int *item);
void peek(Stack *s,int *item);
void travers(Stack *s);
void revers(Stack *s);

int main()
{
    Stack *s;
    init(&s);
    int choice;
    int *item;
    while(1)
    {
        printf("\tMENU\n");
        printf("[1]PUSH\n");
        printf("[2]POP\n");
        printf("[3]PEEK\n");
        printf("[4]TRAVERS\n");
        printf("[5]REVERS\n");
        printf("[6]EXIT\n");

        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Your Item:");
                scanf("%d",&item);
                push(&s,&item);
                break;
            case 2:
                pop(&s,&item);
                break;
            case 3:
                peek(&s,&item);
                break;
            case 4:
                travers(&s);
                break;
            case 5:
                revers(&s);
                break;
            case 6:
                exit(0);
                break;
        }
    }
    return 0;
}
void push(Stack *s,int *item)
{
    if(isFull(s))
    {
        printf("Stack is Full\n");
    }
    else
    {
        (s->top)++;
        s->ele[s->top]=*item;
    }
}
int isFull(Stack *s)
{
    if(s->top==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pop(Stack *s,int *item)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        *item=s->ele[s->top];
        printf("%d is Deleted\n",*item);
        (s->top)--;
    }
}
int isEmpty(Stack *s)
{
    //(s.top)*
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek(Stack *s,int *item)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        *item=s->ele[s->top];
        printf("%d is Peek Element\n",*item);
    }
}
void travers(Stack *s)
{
    for(int i=s->top;i>=0;i--)
    {
        printf("%d\n",s->ele[i]);
    }
}
void revers(Stack *s)
{

    for(int i=0;i<=s->top;i++)
    {
        printf("%d\n",s->ele[i]);
    }
}
