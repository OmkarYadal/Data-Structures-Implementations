//Priority queue in serial order

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
    int i,choice,ele;
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
            case 1: printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                if(q[0].count != size)
                    insert(&q[0],ele);
                else if(q[1].count != size)
                    insert(&q[1],ele);
                else if(q[2].count != size)
                    insert(&q[2],ele);
                else
                    printf("All queues are full\n");
                break;

            case 2: if(q[0].count != 0)
            {
                ele = del(&q[0]);
                printf("The element deleted from 1st queue is %d\n",ele);
            }
            else if(q[1].count != 0)
            {
                ele = del(&q[1]);
                printf("The element deleted from 2nd queue is %d\n",ele);
            }
            else if(q[2].count != 0)
            {
                ele = del(&q[2]);
                printf("The element deleted from 3rd queue is %d\n",ele);
            }
            else
                printf("All the queues are empty\n");
            break;

            case 3: printf("Elements of 1st queue are\n");
                    display(q[0]);
                    printf("Elements of 2nd queue are\n");
                    display(q[1]);
                    printf("Elements of 3rd queue are\n");
                    display(q[2]);
                break;

            case 4: exit(0);

            default : printf("Enter the correct input\n");
        }
    }
    return 0;
}

void insert(S *q,int ele)
{
    q->rear = (q->rear + 1)%size;
    q->a[q->rear] = ele;
    q->count++;
}

int del(S *q)
{
    int ele;
    ele = q->a[q->front];
    q->front = (q->front + 1)%size;
    q->count--;
    return ele;
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
