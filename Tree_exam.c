#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int info;
    struct tree *left,*right;
};
typedef struct tree * nodeptr;
nodeptr getnode();
void freenode(nodeptr);
nodeptr insert(nodeptr,int);
void inorder(nodeptr);
int count(nodeptr);
int internalnode(nodeptr);
int main()
{
    nodeptr t = NULL;
    int choice,ele,nodes,internalnodes;
    while(1)
    {
        printf("\nThe choices are as follows\n");
        printf("1:Insert\t2:Inorder traversal\t3:Number of nodes\t4:Number of Internal nodes\t5:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    t = insert(t,ele);
                    break;

            case 2: printf("The inorder traversal of the tree is\n");
                    inorder(t);
                    break;

            case 3: nodes = count(t);
                    printf("The number of nodes is %d\n",nodes);
                    break;

            case 4: internalnodes = internalnode(t);
                    printf("The number of leaf nodes in the tree are %d\n",internalnodes);
                    break;

            case 5: exit(0);

            default : printf("Enter the correct choice\n");
        }
    }
    freenode(t);
    return 0;
}

nodeptr getnode()
{
    nodeptr p;
    p = (nodeptr)malloc(sizeof(struct tree));

    if(p == NULL)
    {
        printf("Memory allocation fails\n");
        exit(0);
    }
    return p;
}

void freenode(nodeptr t)
{
    free(t);
}

nodeptr insert(nodeptr t,int ele)
{
    nodeptr p;
    p = getnode();
    p->info = ele;
    p->right = p->left = NULL;
    if(t == NULL)
        return p;
    else
    {
        nodeptr curr,prev;
        prev = NULL;
        curr = t;
        while(curr != NULL)
        {
            prev = curr;
            if(ele == curr->info)
            {
                printf("Duplicate element found\n");
                return t;
            }
            else if(ele < curr->info)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if(ele < prev->info)
        {
            prev->left = p;
            return t;
        }
        else
        {
            prev->right = p;
            return t;
        }
    }
}

void inorder(nodeptr t)
{
    nodeptr p = t;
    if(p == NULL)
        return;
    inorder(p->left);
    printf("%d\n",p->info);
    inorder(p->right);
}

int count(nodeptr t)
{
    nodeptr p = t;
    if(p == NULL)
        return 0;
    else
    {
        return 1 + count(p->left) + count(p->right);
    }
}

int internalnode(nodeptr t)
{
    nodeptr p = t;
    if(p == NULL)
        return 0;
    else
    {
        if(p->left == NULL && p->right == NULL)
            return 0;
        else
            return 1 + internalnode(p->left) + internalnode(p->right);
    }
}
