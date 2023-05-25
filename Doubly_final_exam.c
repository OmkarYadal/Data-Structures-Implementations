//Doubly linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *right,*left;
};
typedef struct node * nodeptr;
nodeptr getnode();
void freenode(nodeptr);
nodeptr insrear(nodeptr,int);
nodeptr keycheck(nodeptr,int);
void display(nodeptr);
int main()
{
    nodeptr l = NULL;
    int choice,ele;
    while(1)
    {
        printf("\nThe choices are as follows\n");
        printf("1:Keycheck and Insert\t2:Display\t3:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the key element\n");
                    scanf("%d",&ele);
                    l = keycheck(l,ele);
                    break;

            case 2: display(l);
                    break;

            case 3: exit(0);

            default : printf("Enter the correct choice\n");
        }
    }
    freenode(l);
    return 0;
}

nodeptr getnode()
{
    nodeptr p;
    p = (nodeptr)malloc(sizeof(struct node));

    if(p == NULL)
    {
        printf("Memory allocation fails\n");
        exit(0);
    }
    return p;
}

void freenode(nodeptr l)
{
    free(l);
}

void display(nodeptr l)
{
    nodeptr p;
    if(l == NULL)
        printf("Linked list is empty\n");
    else
    {
        printf("\nThe elements of the linked list are\n");
        for(p = l; p != NULL; p = p->right)
            printf("%d\n",p->info);
    }
}

nodeptr keycheck(nodeptr l,int ele)
{
    int pos = 0;
    nodeptr p;
    if(l == NULL)
        l = insrear(l,ele);
    else
    {
        for(p = l; p != NULL; p = p->right)
        {
            pos++;
            if(ele == p->info)
            {
                printf("\nKey element found\n");
                printf("Position of the element is %d\n",pos);
                return l;
            }
        }
        l = insrear(l,ele);
    }
    return l;
}

nodeptr insrear(nodeptr l,int ele)
{
    nodeptr p,q;
    p = getnode();
    p->info = ele;
    p->left = p->right = NULL;
    if(l == NULL)
        return p;
    else if(l->right == NULL)
    {
        l->right = p;
        p->left = l;
    }
    else
    {
        for(q = l; q->right != NULL; q = q->right)
            ;
        q->right = p;
        p->left = q;
    }
    return l;
}
