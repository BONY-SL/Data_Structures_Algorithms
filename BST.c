//
// Created by danid on 8/30/2023.
//
#include<stdio.h>
#include<stdlib.h>
struct node_tree
{
    int data;
    struct node_tree *right;
    struct node_tree *left;
};
struct node_tree *root=NULL;
void Insert_Node(int value);
void Delete_Node(int delete_value);
void Search_Node(int Search_value);
void In_Oder_Travel(struct node_tree *temp);
void Post_Oder_Travel(struct node_tree *temp);
void Pre_Oder_Travel(struct node_tree *temp);

int main()
{
    int choice;
    int element;
    int element_d;
    while(1)
    {
        printf("\n\t***MENU***\n");
        printf("[1]Insert Node\n");
        printf("[2]Delete Node\n");
        printf("[3]Search Node\n");
        printf("[4]In order Display\n");
        printf("[5]Post order Display\n");
        printf("[6]Pre order Display\n");
        printf("[7]Exit\n\n");
        printf("What is your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter Your data add to Node:");
                scanf("%d",&element);
                Insert_Node(element);
                break;
            case 2:
                if(root==NULL)
                {
                    printf("Can not delete any nodes Tree is Empty\n");
                }
                else
                {
                    printf("Enter Your Element to Delete in the tree:");
                    scanf("%d",&element_d);
                    Delete_Node(element_d);
                }
                break;
            case 3:
                if(root==NULL)
                {
                    printf("Can not Search any nodes Tree is Empty\n");
                }
                else
                {
                    printf("Enter Your Element to Search in the tree:");
                    scanf("%d",&element_d);
                    Search_Node(element_d);
                }
                break;
            case 4:
                if(root==NULL)
                {
                    printf("Tree is Empty\n");
                }
                else
                {
                    printf("\nIn_Order***\n");
                    In_Oder_Travel(root);
                }
                break;
            case 5:
                if(root==NULL)
                {
                    printf("Tree is Empty\n");
                }
                else
                {
                    printf("\nPost_Order***\n");
                    Post_Oder_Travel(root);
                }
                break;
            case 6:
                if(root==NULL)
                {
                    printf("Tree is Empty\n");
                }
                else
                {
                    printf("\nPre_Order***\n");
                    Pre_Oder_Travel(root);
                }
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid Input\n\n");
        }
    }
    return 0;
}
void Insert_Node(int value)
{
    struct node_tree *temp;
    struct node_tree *parent;
    temp=(struct node_tree*)malloc(sizeof(struct node_tree));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    parent=root;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node_tree *current;
        current=root;
        while(current)
        {
            parent=current;
            if(temp->data > current->data)
            {
                current=current->right;
            }
            else if(temp->data < current->data)
            {
                current=current->left;
            }
            else if(temp->data==current->data)
            {
                printf("**can not add element %d is all ready added**\n",temp->data);
                break;
            }
        }
        if(temp->data > parent->data)
        {
            parent->right=temp;
        }
        else if(temp->data < parent->data)
        {
            parent->left=temp;
        }
    }

}
void Delete_Node(int delete_value)
{
    struct node_tree *parent;
    struct node_tree *current;
    parent=root;
    current=root;
    while(current)
    {
        if(delete_value==current->data)
        {
            //Delete Node having no children
            if(current->left==NULL && current->right==NULL)
            {
                if(parent->right==current)
                {
                    printf("%d is deleted\n",current->data);
                    parent->right=NULL;
                    free(current);
                    break;
                }
                else if(parent->left==current)
                {
                    printf("%d is deleted\n",current->data);
                    parent->left=NULL;
                    free(current);
                    break;
                }
            }
                //Delete node having one children(have right sub tree)
            else if(current->right!=NULL && current->left==NULL)
            {
                if(parent->left==current)
                {
                    printf("%d is deleted\n",current->data);
                    parent->left=current->right;
                    current->right=NULL;
                    free(current);
                    break;
                }
                else if(parent->right==current)
                {
                    printf("%d is deleted\n",current->data);
                    parent->right=current->right;
                    current->right=NULL;
                    free(current);
                    break;
                }
            }
                //Delete node having one children(have left sub tree)
            else if(current->left!=NULL && current->right==NULL)
            {
                if(parent->left==current)
                {
                    printf("%d is deleted\n",current->data);
                    parent->left=current->left;
                    current->left=NULL;
                    free(current);
                    break;
                }
                else if(parent->right==current)
                {
                    printf("%d is deleted\n",current->data);
                    parent->right=current->left;
                    current->left=NULL;
                    free(current);
                    break;
                }
            }
                //Delete node having two children
            else if(current->left!=NULL && current->right!=NULL)
            {
                struct node_tree *least;
                struct node_tree *temp2;
                least=current->right;
                temp2=current;
                if(least->right==NULL && least->left==NULL)
                {
                    printf("%d is deleted\n",current->data);
                    current->data=least->data;
                    current->right=NULL;
                    free(least);
                    break;
                }
                else if(least->right!=NULL && least->left==NULL)
                {
                    printf("%d is deleted\n",current->data);
                    current->data=least->data;
                    current->right=least->right;
                    least->right=NULL;
                    free(least);
                    break;
                }
                else
                {
                    while(least->left!=NULL)
                    {
                        temp2=least;
                        least=least->left;
                    }
                    if(least->right!=NULL)
                    {
                        printf("%d is deleted\n",current->data);
                        current->data=least->data;
                        temp2->left=least->right;
                        least->right=NULL;
                        free(least);
                        break;
                    }
                    else
                    {
                        printf("%d is deleted\n",current->data);
                        current->data=least->data;
                        temp2->left=NULL;
                        free(least);
                        break;
                    }
                }
            }
        }
        else if(delete_value > current->data)
        {
            parent=current;
            current=current->right;
        }
        else
        {
            parent=current;
            current=current->left;
        }
    }
    if(current==NULL)
    {
        printf("%d is not in the tree\n",delete_value);
    }
}
void Search_Node(int Search_value)
{
    struct node_tree *current;
    current=root;

    while(current)
    {
        if(Search_value==current->data)
        {
            printf("%d is have in the Tree\n",Search_value);
            break;
        }
        else if(Search_value > current->data)
        {
            current=current->right;
        }
        else if(Search_value < current->data)
        {
            current=current->left;
        }
    }
    if(current==NULL)
    {
        printf("%d is not have in the Tree\n",Search_value);
    }
}
void In_Oder_Travel(struct node_tree *temp)
{
    if(temp->left)
    {
        In_Oder_Travel(temp->left);
    }
    printf("%d\n",temp->data);
    if(temp->right)
    {
        In_Oder_Travel(temp->right);
    }
}
void Post_Oder_Travel(struct node_tree *temp)
{
    if(temp->left)
    {
        Post_Oder_Travel(temp->left);
    }
    if(temp->right)
    {
        Post_Oder_Travel(temp->right);
    }
    printf("%d\n",temp->data);
}
void Pre_Oder_Travel(struct node_tree *temp)
{
    printf("%d\n",temp->data);
    if(temp->left)
    {
        Pre_Oder_Travel(temp->left);
    }
    if(temp->right)
    {
        Pre_Oder_Travel(temp->right);
    }
}
