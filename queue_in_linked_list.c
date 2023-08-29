//
// Created by danid on 8/30/2023.
//
//queue in list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *rear=NULL;
void initialized(struct node *s);
void enqueue(struct node *s,int x);
void dequeue(struct node *s);
int IsEmpty();
void display(struct node *s);
int Length();
int main()
{
    struct node *new_node;
    int element;
    int choice;
    while(1)
    {
        printf("\t\t****MENU****\t\n");
        printf("[1].enqueue Element\n");
        printf("[2].dequeue Element\n");
        printf("[3].Display\n");
        printf("[4].Create queue List\n");
        printf("[5].Exit\n\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Your Element:");
                scanf("%d",&element);
                enqueue(new_node,element);
                break;
            case 2:
                dequeue(new_node);
                break;
            case 3:
                display(new_node);
                break;
            case 4:
                initialized(new_node);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
    return 0;
}

void initialized(struct node *s)
{
    struct node *temp;
    s=(struct node*)malloc(sizeof(struct node));
    printf("Enter Your Element:");
    scanf("%d",&s->data);
    s->next=NULL;
    if(head==NULL)
    {
        head=s;
        rear=s;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=s;
        rear=s;
    }
}
void enqueue(struct node *s,int x)
{
    struct node *temp;
    s=(struct node*)malloc(sizeof(struct node));
    s->data=x;
    s->next=NULL;
    if(head==NULL)
    {
        head=s;
        rear=s;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=s;
        rear=s;
    }
    printf("last Element is %d\n",rear->data);
}
void dequeue(struct node *s)
{
    struct node *temp;
    if(IsEmpty())
    {
        printf("List is Empty\n");
    }
    else
    {
        temp=head;
        head=temp->next;
        printf("%d is Deleted\n",temp->data);
        if(head==NULL)
        {
            rear=NULL;
        }
        free(temp);
    }
}
int IsEmpty()
{
    if(head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(struct node *s)
{
    s=head;
    if(IsEmpty())
    {
        printf("List is Empty\n");
    }
    else
    {
        while(s!=NULL)
        {
            printf("%d\n",s->data);
            s=s->next;
        }
    }
}
