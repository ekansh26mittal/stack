#include<stdio.h>

typedef struct ll
{
    int i;
    Node * next;

}Node;

void main()
{}



//create
//traverse
//search
//insb
//inse
//insm
//delb
//dele
//delm


Node * create(int x)
{
    Node *p = malloc(sizeof(Node));
    p->i=x;
    p->next = NULL;
     Node * h = p;
     return h;   
}

void insertb(Node *h , int x)
{
    Node *p = malloc(sizeof(Node));
    p->i =x;
    p->next = h;
    h=p;
}

Node * traverse(Node *h)
{
    Node * p;
    p =h;

    while(p != NULL)
    {p = p->next;}
    return p;
}

void insterte(Node *h, int x )
{
    Node *p = malloc(sizeof(Node));
    p->i=x;

   Node * t1 = traverse(h);
   t1->next = p;
   p->next = NULL;  
}

void interstm(Node *h, int x, int i )
{
    Node *p = malloc(sizeof(Node));
    p->i= x;
    Node * t1, *t2;
    t1=h;t2=t1->next;
    
    for(int k =1;k<i;k++)
    {
        t1=t1->next;
        t2= t2->next;
    }
    t1->next = p;
    p->next = t2;
}


void printl(Node *h)
{
    while(p != NULL)
    {
        printf("%d",p->i);
        p = p->next;
    }
    return p;
}