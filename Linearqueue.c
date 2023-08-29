//
// Created by danid on 8/30/2023.
//
//lenear queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int arr[MAX];
int front=-1;
int rear=-1;

void enqueue();
void dequeue();
void Display_Front();
void TraversElement();
void reversqueue();
int isFull();
int isEmpty();

int main()
{
    int choice;
    while(1)
    {
        printf("\tMENU\n");
        printf("[1].enqueue\n");
        printf("[2].dequeue\n");
        printf("[3].Display Front\n");
        printf("[4].TraversElement\n");
        printf("[5].reversqueue\n");
        printf("[6].Exit\n\n");

        printf("Enter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                Display_Front();
                break;
            case 4:
                TraversElement();
                break;
            case 5:
                reversqueue();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }
    return 0;
}
void enqueue()
{
    if(isFull())
    {
        printf("queue is Full\n");
    }
    else
    {
        int element;
        printf("Enter Your Element:");
        scanf("%d",&element);
        if(front==-1)
        {
            front=0;
        }
        rear++;
        arr[rear]=element;
    }
}
int isFull()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void dequeue()
{
    if(isEmpty())
    {
        printf("queue is Empty\n");
    }
    else
    {
        printf("%d is Deleted\n",arr[front]);
        front++;
        if(front==rear+1)
        {
            front=-1;
            rear=-1;
        }
    }
}
int isEmpty()
{
    if(front==-1 || front==rear+1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Display_Front()
{
    if(isEmpty())
    {
        printf("queue is Empty\n");
    }
    else
    {
        printf("%d is Front Element\n",arr[front]);

    }
}
void TraversElement()
{
    if(isEmpty())
    {
        printf("queue is Empty\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",arr[i]);
        }

    }
}
void reversqueue()
{
    if(isEmpty())
    {
        printf("queue is Empty\n");
    }
    else
    {
        for(int i=rear;i>=front;i--)
        {
            printf("%d\n",arr[i]);
        }

    }
}

