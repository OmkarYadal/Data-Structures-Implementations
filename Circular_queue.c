//Circular queue implementation

#include<stdio.h>
#include<stdlib.h>
#define size 5
struct queue
{
    int a[size];
    int front,rear;
};
typedef struct queue S;
void insert(S *,int);
int del(S *);
void display(S);
int main()
{
    S q;
    q.front = -1;
    q.rear = -1;
    int choice,ele;

    while(1)
    {
        printf("\nThe choices are as follows\n");
        printf("1:Insert\t2:Delete\t3:Display\t4:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insert(&q,ele);
                break;

            case 2: ele = del(&q);
                if(ele == -1)
                    printf("The queue is empty\n");
                else
                    printf("The deleted element is %d\n",ele);
                break;

            case 3: display(q);
                break;

            case 4: exit(0);

            default : printf("Enter the correct input\n");
        }
    }
    return 0;
}

void insert(S *q,int ele)
{
    if(q->rear == size - 1 && q->front != 0)
    {
        q->rear = 0;
        q->a[q->rear] = ele;
    }
    else if(q->rear == size - 1 || q->rear == (q->front - 1)%(size - 1))
        printf("The queue is full\n");

    else if(q->rear == -1)
    {
        q->rear = q->front = 0;
        q->a[q->rear] = ele;
    }
    else
        q->a[++q->rear] = ele;
}

int del(S *q)
{
    int ele;
    if(q->rear == -1)
        return -1;
    else
    {
        ele = q->a[q->front];
        if(q->rear == q->front)
            q->rear = q->front = -1;
        else if(q->front == size - 1)
            q->front = 0;
        else
            q->front++;
        return ele;
    }
}

void display(S q)
{
    int i;
    if(q.rear == -1)
        printf("The queue is empty\n");
    else if(q.rear < q.front)
    {
        printf("The queue elements are\n");
        for(i=q.front; i<=size - 1; i++)
            printf("%d\n",q.a[i]);
        for(i=0; i<=q.rear; i++)
            printf("%d\n",q.a[i]);
    }
    else
    {
         printf("The queue elements are\n");
         for(i=q.front; i<=q.rear; i++)

                printf("%d\n",q.a[i]);
    }
}
