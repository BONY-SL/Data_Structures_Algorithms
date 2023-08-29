//
// Created by danid on 8/30/2023.
//
//Circuler queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX];
int front=-1;
int rear=-1;

void enqueue(int Element);
void dequeue();
void Display_Front();
void TraversElement();
void reversqueue();

int main()
{
    int choice;
    int Element;
    while(1)
    {
        printf("\tMENU\n");
        printf("[1].enqueue\n");
        printf("[2].dequeue\n");
        printf("[3].Display_Front\n");
        printf("[4].TraversElement\n");
        printf("[5].reversqueue\n");
        printf("[6].Exit\n");

        printf("\nEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Your Element:");
                scanf("%d",&Element);
                enqueue(Element);
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
        }
    }
    return 0;
}
void enqueue(int Element)
{

    if((front==0 && rear==MAX-1)||(front==rear+1))
    {
        printf("Is Full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        arr[rear]=Element;
    }
    else if(rear==MAX-1)
    {
        rear=0;
        arr[rear]=Element;
    }
    else
    {
        ++rear;
        arr[rear]=Element;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("is Empty\n");
    }
    else if(front==rear)
    {
        printf("%d is deleted\n",arr[front]);
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1)
    {
        printf("%d is deleted\n",arr[front]);
        front=0;
    }
    else
    {
        printf("%d is deleted\n",arr[front]);
        ++front;
    }
}
void Display_Front()
{
    if(front==-1 && rear==-1)
    {
        printf("is Empty\n");
    }
    else
    {
        printf("%d is Front Element\n",arr[front]);
        printf("%d is Rear Element\n",arr[rear]);
    }
}
void TraversElement()
{
    if(front==-1 && rear==-1)
    {
        printf("is Empty\n");
    }
    else if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",arr[i]);
        }
    }
    else if(front==rear+1 || rear!=-1)
    {
        for(int i=front;i<MAX;i++)
        {
            printf("%d\n",arr[i]);
        }
        if(rear!=-1)
        {
            for(int i=0;i<=rear;i++)
            {
                printf("%d\n",arr[i]);
            }
        }
    }
}
void reversqueue()
{
    if(front==-1 && rear==-1)
    {
        printf("is Empty\n");
    }
    else if(front<=rear)
    {
        for(int i=rear;i>=front;i--)
        {
            printf("%d\n",arr[i]);
        }
    }
    else if(front==rear+1 || rear!=-1)
    {
        for(int i=rear;i>=0;i--)
        {
            printf("%d\n",arr[i]);
        }
        for(int i=MAX-1;i>=front;i--)
        {
            printf("%d\n",arr[i]);
        }
    }
}

