#include <stdio.h>

typedef struct stk
{
    int top;
   // int size;
    char a[30];

} Stack;

void push(Stack *s, char x);
char pop(Stack *s);
void printst(Stack *s);
char peek(Stack *s);
int full(Stack *s);
int empty(Stack *s);

void main()
{
    Stack main;
    main.top = -1;
   // main.size = 30;

    push(&main , '1');
    push(&main ,'2');
    push(&main ,'3');
    printst(&main);

    // (a+ b*c)-(d+e\f)
}

// push- adds value to stack
// pop - removes and reads value from stack
// peak- to read the top value

void push(Stack *s, char x)
{
    if (!full(&s))
    {
        s->top++;
        s->a[s->top] = x;
    }
}
char pop(Stack *s)
{
    char x;
    if (!empty(&s))
    {
        x = s->a[s->top];
        s->top--;
    }
    return x;
}
void printst(Stack *s)
{
    if (!empty(&s))
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%c", s->a[i]);
        }
    }
}
char peek(Stack *s)
{
    char x;
    if (!empty(&s))
    {
        x = s->a[s->top];
    }
    return x;
}
int full(Stack * s)
{
    if (s->top ==29)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int empty(Stack * s)
{
    if (s->top != -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}