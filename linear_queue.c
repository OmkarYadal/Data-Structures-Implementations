//Linear queue

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool empty(S);
bool overflow(S);
int main()
{
    int choice,ele;
    S q;
    q.front = 0;
    q.rear = -1;
    while(1)
    {
        printf("\nThe choices are as follows\n");
        printf("1:Insert\t2:Delete\t3:Display\t4:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(!overflow(q))
                {
                    printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    insert(&q,ele);
                }
                else
                    printf("The queue is full\n");
                    break;

            case 2: if(!empty(q))
                    {
                        ele = del(&q);
                        printf("The deleted element is %d\n",ele);
                    }
                    else
                        printf("The queue is empty\n");
                    break;

            case 3: if(!empty(q))
                    {
                        display(q);
                    }
                    else
                        printf("Queue is empty\n");
                    break;

            case 4: exit(0);

            default : printf("Enter the correct choice\n");
        }
    }
    return 0;
}

int del(S *q)
{
        return q->a[q->front++];
}

bool empty(S q)
{
    return (q.front > q.rear);
}

void insert(S *q,int ele)
{
        q->a[++q->rear] = ele;
}

bool overflow(S q)
{
    return (q.rear == size - 1);
}

void display(S q)
{
    int i;
        printf("The queue elements are as follows\n");
        for(i = q.front; i<=q.rear; i++)
            printf("%d\n",q.a[i]);
}
