#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int a[30];
    int f;
    int r;
}Queue;


void dequeue(Queue * q);
void enqueue(Queue * q , int x);
int full(Queue * q );
int empty(Queue * q);

void main()
{
    struct queue qmain;
    qmain.r = -1;
    qmain.f = -1;

    enqueue(&qmain , 1);
    enqueue(&qmain ,2);
    dequeue(&qmain);
    enqueue(&qmain ,3);
    enqueue(&qmain ,4);
    while(qmain.f != -1)
    {
        dequeue(&qmain);
    }  

}



//enqueue //dequeue //isfull //isempty 

int empty(Queue * q)
{
    if(q->r == q->f && q->f == -1)
    {return 1;}
    else
    {return 0;}
}

int full(Queue * q )
{
    if(q->r = 29)
    {return 1;}
    else
    {return 0;}
}

void enqueue(Queue * q , int x)
{
    if(empty(q))
    {
        q->f =0;
        q->r = 0 ;
        q->a[q->r] = x;
        printf("%d enqueued\n",x);
    }
    else if(!full(q))
    {
        q->r++;
        q->a[q->r]=x;
         printf("%d enqueued\n",x);
    }
    else 
    printf("queue full\n");
}

void dequeue(Queue * q)
{
    int x;
    if(q->r == q->f)
    {
        x = q->a[q->f];
        q->r = -1;
        q->f = -1;
         printf("%d denqueued\n",x);
    }
    else if(!empty(q))
    {
         x = q->a[q->f];
         q->f++;
          printf("%d dequeued\n",x);
    }
    else
    printf("queue empty\n");
}