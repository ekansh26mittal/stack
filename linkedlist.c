#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int i;
    struct Node *next;

} Node;

Node *create(int x);
Node *traverse(Node *h);
void insB(Node *h, int x);
void insE(Node *h, int x);
void insM(Node *h, int x, int i);
void printl(Node *h);
void delB(Node *h);
void delE(Node *h);
void delM(Node *h, int i);

void main()
{
    int a;
    printf("enter 1st node");
    scanf("%d", &a);
    Node *h = create(a);

    while (1)
    {
        printf("press =>   1           insert at begin\n");
        printf("           2           insert at index i\n");
        printf("           3           insert at end\n");
        printf("           4           print the list \n");

        int i;
        scanf("%d", &i);
        int b, i1;
        switch (i)
        {
        case 1:
            printf("enter value : \n");
            scanf("%d", &b);
            insB(h, b);
            break;

        case 2:
            printf("enter value : \n");
            scanf("%d", &b);
            printf("enter index");
            scanf("%d", &i1);
            insM(h, b, i1);
            break;

        case 3:
            printf("enter value : \n");
            scanf("%d", &b);
            insE(h, b);
            break;

        case 4:
            printl(h);
            break;

        default:
            break;
        }
        if (i != 1 || i != 2 || i != 3 || i != 4)
        {
            break;
        }
        // if (i >4)
        // {
        //     break;
        // }
    }
}

// create
// traverse
// search
// insb
// inse
// insm
// delb
// dele
// delm

Node *create(int x)
{
    Node *p = malloc(sizeof(Node));
    p->i = x;
    p->next = NULL;
    Node *h = p;
    return h;
}

Node *traverse(Node *h)
{
    Node *p;
    p = h;

    while (p != NULL)
    {
        p = p->next;
    }
    return p;
}

void insB(Node *h, int x)
{
    Node *p = malloc(sizeof(Node));
    p->i = x;
    p->next = h;
    h = p;
}
void insE(Node *h, int x)
{
    Node *p = malloc(sizeof(Node));
    p->i = x;

    Node *t1 = traverse(h);
    t1->next = p;
    p->next = NULL;
}

void insM(Node *h, int x, int i)
{
    Node *p = malloc(sizeof(Node));
    p->i = x;
    Node *t1, *t2;
    t1 = h;
    t2 = t1->next;

    for (int k = 0; k < i; k++)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    t1->next = p;
    p->next = t2;
}

void printl(Node *h)
{
    Node *p;
    p = h;
    while (p != NULL)
    {
        printf("%d", p->i);
        p = p->next;
    }
    //  return p;
}

void delB(Node *h)
{
    Node *p;
    p = h;
    h = p->next;
    p->next = NULL;
    free(p);
}

void delE(Node *h)
{
    Node *t1 = traverse(h->next);
    Node *t2 = traverse(h);
    t1->next = NULL;
    free(t2);
}

void delM(Node *h, int i)
{
    Node *t1, *t2;
    t1 = h;
    t2 = t1->next;

    for (int k = 0; k < i; k++)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    t1->next = t2->next;
    t2->next = NULL;
    free(t2);
}