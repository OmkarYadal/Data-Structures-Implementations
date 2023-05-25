#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack
{
    int a[size];
    int top;
};
typedef struct stack S;
void push(S *,int);
int pop(S *);
void display(S);
int main()
{
    S A;
    A.top = -1;
    int choice,ele;
    printf("The choices are as follows\n");
    printf("1:Push\t2:Pop\t3:Display\t4:Exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be pushed on to the stack\n");
                scanf("%d",&ele);
                push(&A,ele);
                break;
            case 2: ele = pop(&A);
                printf("The popped element is %d\n",ele);
                break;
            case 3: display(A);
                break;
            case 4: exit(0);
        }
    }
}

void push(S *A,int ele)
{
    if(A->top == size - 1)
        printf("The stack is full\n");
    else
        A->a[++A->top] = ele;
}

int pop(S *A)
{
    if(A->top == -1)
        printf("The stack is empty\n");
    else
        return (A->a[A->top--]);
}

void display(S A)
{
    int i;
    printf("The stack elements are as follows\n");
    for(i=0; i <= A.top; i++)
        printf("%d\n",A.a[i]);
}
