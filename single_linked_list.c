//
// Created by danid on 8/30/2023.
//
//linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int a;
    struct node *next;
};

struct node *head=NULL;

void display();
void display_first_element();
void display_last_element();
void display_select_node();
void scearch_element();
void insertBegin();
void insertEnd();
void insertmiddle();
void deleteBegin();
void deleteEnd();
void deletemiddle();
int Length();

int main()
{
    int choice;
    while(1)
    {
        printf("\tMENU\n");
        printf("[0]display\n");
        printf("[1]insertBegin\n");
        printf("[2]insertEnd\n");
        printf("[3]insertmiddle\n");
        printf("[4]deleteBegin\n");
        printf("[5]deleteEnd\n");
        printf("[6]deletemiddle\n");
        printf("[7]display_first_element\n");
        printf("[8]display_last_element\n");
        printf("[9]display_select_node\n");
        printf("[10]scearch_element\n");
        printf("[11]Length\n");
        printf("[12]Exit\n");

        printf("Enter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                display();
                break;
            case 1:
                insertBegin();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertmiddle();
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deletemiddle();
                break;
            case 7:
                display_first_element();
                break;
            case 8:
                display_last_element();
                break;
            case 9:
                display_select_node();
                break;
            case 10:
                scearch_element();
                break;
            case 11:
                printf("Have %d Nodes\n",Length());
                break;
            case 12:
                exit(0);
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }
    return 0;
}
void insertBegin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory is not Allocated\n");
    }
    else
    {
        printf("Enter Your Element:");
        scanf("%d",&temp->a);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            printf("%d is added\n",temp->a);
        }
        else
        {
            temp->next=head;
            printf("%d is added\n",temp->a);
            head=temp;
        }
    }
}
void insertEnd()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory is not Allocated\n");
    }
    else
    {
        printf("Enter Your Element:");
        scanf("%d",&temp->a);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            printf("%d is added\n",temp->a);
        }
        else
        {
            struct node *p;
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            printf("%d is added\n",temp->a);
        }
    }
}
void insertmiddle()
{
    struct node *temp;
    struct node *p;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory is not Allocated\n");
    }
    else
    {
        int location;
        printf("Enter Your Element:");
        scanf("%d",&temp->a);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            printf("%d is added\n",temp->a);
        }
        else
        {
            p=head;
            printf("What is the Location You Want Add:");
            scanf("%d",&location);
            int len=Length();
            if(location>len)
            {
                printf("Invalid Location Link List have %d nodes\n",len);
            }
            else if(p->next==NULL || location==1)
            {
                temp->next=head;
                printf("%d is added\n",temp->a);
                head=temp;
            }
            else
            {
                int i=1;
                while(i<location-1)
                {
                    p=p->next;
                    ++i;
                }
                temp->next=p->next;
                p->next=temp;
                printf("%d is added\n",temp->a);
            }
        }
    }
}
int Length()
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        int count=0;
        struct node *p;
        p=head;
        while(p!=NULL)
        {
            ++count;
            p=p->next;
        }
        return count;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct node *p;
        p=head;
        while(p!=NULL)
        {
            printf("%d->",p->a);
            p=p->next;
        }
        printf("\n");
    }
}
void deleteBegin()
{
    struct node *p;
    p=head;
    if(p==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        head=p->next;
        printf("%d is deleted\n",p->a);
        p->next=NULL;
        free(p);
    }
}
void deleteEnd()
{
    struct node *p;
    p=head;
    if(p==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        if(p->next==NULL)
        {
            head=NULL;
            printf("% is deleted\n",p->a);

        }
        else
        {
            struct node *temp;
            temp=head->next;
            while(temp->next!=NULL)
            {
                temp=temp->next;
                p=p->next;
            }
            printf("% is deleted\n",temp->a);
            p->next=NULL;
            free(temp);
        }
    }
}
void deletemiddle()
{
    struct node *temp;
    struct node *p;
    p=head;
    if(p==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int location;
        int len=Length();
        printf("Enter Your Location To delete:");
        scanf("%d",&location);
        if(location>len)
        {
            printf("Invalid Location List have %d nodes\n",len);
        }
        else if(p->next==NULL || location==1)
        {
            head=p->next;
            printf("%d is deleted\n",p->a);
            p->next=NULL;
            free(p);
        }
        else if(location==len)
        {
            temp=head->next;
            while(temp->next!=NULL)
            {
                temp=temp->next;
                p=p->next;
            }
            printf("%d is deleted\n",temp->a);
            p->next=NULL;
            free(temp);
        }
        else
        {
            int count=1;
            temp=head->next;
            while(count<location-1)
            {
                temp=temp->next;
                p=p->next;
                ++count;
            }
            p->next=temp->next;
            temp->next=NULL;
            printf("%d is deleted\n",temp->a);
            free(temp);
        }
    }
}
void display_first_element()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("is Empty\n");
    }
    else
    {
        printf("%d is First Node In the List\n",temp->a);
    }
}
void display_last_element()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("is Empty\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        printf("%d is Last Node In the List\n",temp->a);
    }
}
void display_select_node()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int len=Length();
        int selectd;
        printf("Enter Your Location want you slect node:");
        scanf("%d",&selectd);
        if(selectd>len)
        {
            printf("Invalid LOcation List have %d nodes\n",len);
        }
        else
        {
            int i=1;
            while(i<selectd)
            {
                temp=temp->next;
                ++i;
            }
            printf("%d node have %d element\n",i,temp->a);
        }
    }
}
void scearch_element()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int element;
        printf("Enter Your Element");
        scanf("%d",&element);
        while(temp!=NULL)
        {
            if(temp->a==element)
            {
                printf("%d is have in the list\n",element);
                break;
            }
            else
            {
                temp=temp->next;
            }
        }
        if(temp==NULL)
        {
            printf("%d is have not in the list\n",element);
        }
    }
}
