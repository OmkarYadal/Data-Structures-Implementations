//Priority queue in ascending order

#include<stdio.h>
#include<stdlib.h>
#define size 5
struct queue
{
    int a[size];
    int front,rear;
};

typedef struct queue S;
int count = 0;
void insert(S *,int);
int del(S *);
void display(S);
int main()
{
    S q;
    q.front = 0;
    q.rear = -1;
    int choice,ele;
    printf("The choice are as follows\n");
    while(1)
    {
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

            default : printf("Enter the correct choice\n");
        }
    }
    return 0;
}

void insert(S *q,int ele)
{
    int i,j,k = 0;
    if(count == size)
        printf("The queue is full\n");
    else if(q->front == ((q->rear + 1)%size))
    {
        q->rear = (q->rear + 1)%size;
        q->a[q->rear] = ele;
        printf("The inserted element is %d\n",q->a[q->rear]);
        count++;
    }
    else
    {
        i = q->front;
        while(ele >= q->a[i] && k != count)
        {
            i = (i+1)%size;
            k++;
        }

        j = q->rear;
        while(j >= i)
        {
            q->a[(j+1)%size] = q->a[j];
            j--;
        }

        q->a[i] = ele;
        q->rear = (q->rear + 1)%size;
        count++;
    }
}

int del(S *q)
{
    int ele;
    if(count == 0)
        return -1;
    else
    {
        ele = q->a[q->front];
        q->front = (q->front + 1)%size;
        count--;
        return ele;
    }
}

void display(S q)
{
    int i,j;
    if(count == 0)
        printf("Queue is empty\n");
    else
    {
        printf("The queue elements are as follows\n");
        for(i=0,j=q.front; i<count; i++,j = (j+1)%size)
            printf("%d\n",q.a[j]);
    }
}
