//
// Created by danid on 8/30/2023.
//
//stack in list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *top=NULL;
void initialized(struct node *s);
void push(struct node *s,char x);
void pop(struct node *s);
int IsEmpty();
void display(struct node *s);
void reverse(struct node *s);
int Length();
int main()
{
    struct node *new_node;
    char element;
    int choice;
    while(1)
    {
        printf("\t\t****MENU****\t\n");
        printf("[1].Push Element\n");
        printf("[2].Pop Element\n");
        printf("[3].Display\n");
        printf("[4].Create Stack List\n");
        printf("[5]reverse List\n");
        printf("[6].Exit\n\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Your Element:");
                scanf(" %c",&element);
                push(new_node,element);
                break;
            case 2:
                pop(new_node);
                break;
            case 3:
                display(new_node);
                break;
            case 4:
                initialized(new_node);
                break;
            case 5:
                reverse(new_node);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }

    return 0;
}

void initialized(struct node *s)
{
    s=(struct node*)malloc(sizeof(struct node));
    printf("Enter your data to add:");
    scanf(" %c",&s->data);
    s->next=NULL;
    if(s==NULL)
    {
        printf("Not alocated mamory spaces Dinamacaly\n");
    }
    if(top==NULL)
    {
        top=s;
    }
    else
    {
        s->next=top;
        top=s;
    }
}
void push(struct node *s,char x)
{
    s=(struct node*)malloc(sizeof(struct node));
    if(s==NULL)
    {
        printf("Not alocated mamory spaces Dinamacaly\n");
    }
    s->data=x;
    s->next=NULL;
    if(top==NULL)
    {
        top=s;
    }
    else
    {
        s->next=top;
        top=s;
    }

}
void pop(struct node *s)
{
    if(IsEmpty())
    {
        printf("List is Empty\n");
    }
    else
    {
        s=top;
        printf("%c is Deleted\n",s->data);
        top=s->next;
    }
}
int IsEmpty()
{
    if(top==NULL)
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
    s=top;
    int i=Length();
    int a=0;
    char arr[i];
    if(IsEmpty())
    {
        printf("List is Empty\n");
    }
    else
    {
        while(s!=NULL)
        {
            arr[a]=s->data;
            a++;
            s=s->next;
        }
        for(int b=i-1;b>=0;b--)
        {
            printf("%c ",arr[b]);
        }
        printf("\n");
    }

}
//Reverse the implemented stack using reverse
void reverse(struct node *s)
{
    if(IsEmpty())
    {
        printf("List is Empty\n");
    }
    else
    {
        s=top;
        printf("Reverse the implemented stack using reverse\n");
        while(s!=NULL)
        {
            printf("%c ",s->data);
            s=s->next;
        }
        printf("\n\n");
    }
}
int Length()
{
    struct node *s;
    s=top;
    int count=0;
    while(s!=NULL)
    {
        s=s->next;
        ++count;
    }
    return count;
}
