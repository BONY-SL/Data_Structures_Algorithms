//
// Created by danid on 8/30/2023.
//
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *right;
    struct node *left;
};
struct node* head=NULL;
struct node* tail=NULL;
void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete_begin();
void delete_middle();
void delete_end();
void print_head_to_tail();
void print_tail_to_head();
void findElement();
int nodeCount();
int main()
{
    int len;
    int choice;
    while(1)
    {
        printf("\t\t***MENU***\n\n");
        printf("\t[0]Create List\n");
        printf("\t[1]Insert_Begin Element\n");
        printf("\t[2]Insert_Middle Element\n");
        printf("\t[3]Insert_End Element\n");
        printf("\t[4]Dlete Begin Element\n");
        printf("\t[5]Dlete Middle Element\n");
        printf("\t[6]Dlete End Element\n");
        printf("\t[7]Display List(HEAD TO TAIL)\n");
        printf("\t[8]Display List(TAIL TO HEAD)\n");
        printf("\t[9]Find_Element\n");
        printf("\t[10]Node_Count(Length of List)\n");
        printf("\t[11]Exit\n\n");
        printf("\tEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                create();
                break;
            case 1:
                insert_begin();
                break;
            case 2:
                insert_middle();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_middle();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                print_head_to_tail();
                break;
            case 8:
                print_tail_to_head();
                break;
            case 9:
                findElement();
                break;
            case 10:
                len=nodeCount();
                if(len==0)
                {
                    printf("Empty List\n");
                }
                else
                {
                    printf("List have %d nodes\n",len);
                }
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("\nInvalid Input\n");
        }
    }
    return 0;
}
void create()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Your Element:");
    scanf("%d",&temp->num);
    temp->left=NULL;
    temp->right=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        printf("Added\n");
    }
    else
    {
        struct node *p;
        p=head;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
        tail=temp;
        printf("Added\n");
    }
}
void print_head_to_tail()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->num);
            temp=temp->right;
        }
        printf("\n");
    }
}
void print_tail_to_head()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp=tail;
        while(temp!=NULL)
        {
            printf("%d->",temp->num);
            temp=temp->left;
        }
        printf("\n");
    }
}
void insert_begin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Your Element:");
    scanf("%d",&temp->num);
    temp->left=NULL;
    temp->right=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        printf("Added\n");
    }
    else
    {
        head->left=temp;
        temp->right=head;
        head=temp;
        printf("Added\n");
    }
}
void insert_middle()
{
    struct node *temp;
    int length=nodeCount();
    int location;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Location add to Element:");
    scanf("%d",&location);
    if(location>length)
    {
        printf("Invalid Location List have %d locations re Enter valid Location\n",length);
    }
    else
    {
        printf("Enter Your Element:");
        scanf("%d",&temp->num);
        temp->left=NULL;
        temp->right=NULL;

        if(head==NULL)
        {
            head=temp;
            tail=temp;
            printf("Added\n");
        }
        else if(location==1)
        {
            head->left=temp;
            temp->right=head;
            head=temp;
            printf("Added\n");
        }
        else if(location==length)
        {
            temp->right=tail;
            temp->left=tail->left;
            temp->right->left=temp;
            temp->left->right=temp;
            printf("Added\n");
        }
        else
        {
            struct node *p;
            p=head;
            int i=1;
            while(i<location)
            {
                p=p->right;
                ++i;
            }
            temp->right=p;
            temp->left=p->left;
            temp->left->right=temp;
            temp->right->left=temp;
            printf("Added\n");
        }
    }
}
int nodeCount()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        int count=1;
        while(temp->right!=NULL)
        {
            ++count;
            temp=temp->right;
        }
        return count;
    }
}
void insert_end()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Your Element:");
    scanf("%d",&temp->num);
    temp->left=NULL;
    temp->right=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        printf("Added\n");
    }
    else
    {
        struct node *p;
        p=head;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
        tail=temp;
        printf("Added\n");
    }
}
void delete_begin()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is Empty can not delete Element\n");
    }
    else if(temp->right==NULL)
    {
        printf("%d is Deleted\n",temp->num);
        temp=NULL;
        head=temp;
        tail=temp;
        free(temp);
    }
    else
    {
        head=temp->right;
        head->left=NULL;
        temp->right=NULL;
        printf("%d is deleted\n",temp->num);
        free(temp);
    }
}
void delete_middle()
{
    struct node *temp;
    int length=nodeCount();
    int location;
    printf("Enter Location delete to Element:");
    scanf("%d",&location);
    if(location>length || length==0)
    {
        printf("Invalid Location List have %d locations re Enter valid Location\n",length);
    }
    else
    {
        temp=head;
        if(head->right==NULL)
        {
            printf("%d is Deleted\n",temp->num);
            temp=NULL;
            head=temp;
            tail=temp;
            free(temp);
        }
        else if(location==1)
        {
            head=temp->right;
            head->left=NULL;
            temp->right=NULL;
            printf("%d is deleted\n",temp->num);
            free(temp);
        }
        else if(location==length)
        {
            temp=tail;
            tail=temp->left;
            tail->right=NULL;
            temp->left=NULL;
            printf("%d is deleted\n",temp->num);
            free(temp);
        }
        else
        {
            struct node *p;
            p=head;
            int i=1;
            while(i<location)
            {
                p=p->right;
                ++i;
            }
            p->left->right=p->right;
            p->right->left=p->left;
            p->left=NULL;
            p->right=NULL;
            printf("%d is deleted\n",p->num);
            free(p);
        }
    }
}
void delete_end()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else if(head->right==NULL)
    {
        printf("%d is Deleted\n",temp->num);
        temp=NULL;
        head=temp;
        tail=temp;
        free(temp);
    }
    else
    {
        temp=tail;
        tail=temp->left;
        tail->right=NULL;
        temp->left=NULL;
        printf("%d is deleted\n",temp->num);
        free(temp);
    }
}
void findElement()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Can not Find List is Empty\n");
    }
    else
    {
        int element;
        printf("Enter Your Find Element:");
        scanf("%d",&element);
        temp=head;
        while(temp!=NULL)
        {
            if(element==temp->num)
            {
                printf("%d is have in the list\n",element);
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(temp==NULL)
        {
            printf("%d is have not in the list\n",element);
        }
    }
}
