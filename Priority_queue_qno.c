//Priority queue using queue numbers

#include<stdio.h>
#include<stdlib.h>
#define size 5
struct queue
{
    int a[size];
    int front,rear,count;
};
typedef struct queue S;
void insert(S *,int);
int del(S *);
void display(S);
int main()
{
    S q[3];
    int i,choice,qno,ele;
    for(i=0; i<3; i++)
    {
        q[i].front = 0;
        q[i].rear = -1;
        q[i].count = 0;
    }
    printf("The choices are as follows\n");
    while(1)
    {
        printf("1:Insert\t2:Delete\t3:Display\t4:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the queue number\n");
                scanf("%d",&qno);
                printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insert(&q[qno - 1],ele);
                break;

            case 2: printf("Enter the queue number\n");
                scanf("%d",&qno);

                ele = del(&q[qno - 1]);
                if(ele == -1)
                    printf("The queue is empty\n");
                else
                    printf("The deleted element is %d\n",ele);
                break;

            case 3: for(i=0; i<3; i++)
                {
                    printf("The elements of the %d queue are\n",i+1);
                    display(q[i]);
                }
                break;

            case 4: exit(0);

            default : printf("Enter the correct input\n");
        }
    }
    return 0;
}

void insert(S *q,int ele)
{
    if(q->count == size)
        printf("The queue is full\n");
    else
    {
        q->rear = (q->rear + 1)%size;
        q->a[q->rear] = ele;
        q->count++;
    }
}

int del(S *q)
{
    int ele;
    if(q->count == 0)
        printf("The queue is empty\n");
    else
    {
        ele = q->a[q->front];
        q->front = (q->front + 1)%size;
        q->count--;
        return ele;
    }
}

void display(S q)
{
    int i,j;
    if(q.count == 0)
        printf("The queue is empty\n");
    else
    {
        for(i=0,j=q.front; i<q.count; i++,j = (j+1)%size)
            printf("%d\n",q.a[j]);
    }
}
