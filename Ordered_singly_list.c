//Ascending ordered Singly linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node * nodeptr;
nodeptr getnode();
void freenode(nodeptr);
void display(nodeptr);
nodeptr insert(nodeptr,int);
int main()
{
    nodeptr l = NULL;
    int choice,ele;
    while(1)
    {
            printf("\nThe choices are as follows\n");
            printf("1:Insert\t2:Display\t3:Exit\n");
            printf("Enter your choice\n");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: printf("Enter the element to be inserted\n");
                        scanf("%d",&ele);
                        l = insert(l,ele);
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
    else
        return p;
}

void freenode(nodeptr l)
{
    free(l);
}

nodeptr insert(nodeptr l,int ele)
{
    nodeptr p,q,r;
    p = getnode();
    p->info = ele;
    p->next = NULL;
    if(l == NULL)
        return p;
    else if(ele < l->info)
    {
            p->next = l;
            l = p;
            return l;
    }
    else
    {
        for(q = l; q != NULL; q = q->next)
        {
            if(ele < q->info)
            {
                p->next = q;
                r->next = p;
                return l;
            }
            r = q;
        }
            r->next = p;
            return l;
    }
}

void display(nodeptr l)
{
    nodeptr p;
    if(l == NULL)
    {
        printf("The linked list is empty\n");
        return ;
    }
    else
    {
        printf("\nThe elements in the linked list are\n");
        for(p = l; p != NULL; p = p->next)
            printf("%d\n",p->info);
    }
}
