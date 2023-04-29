#include<stdio.h>



typedef struct stk
{
    int top;
    // int size;
    char a[30];

} Stack1;













































int prec(char x)
{
    int p;
    if(x =='+')
    {p=1;}
    if(x== '-')
    {p=0;}
    if(x =='*')
    {p=3;}
    if(x =='/')
    {p=3;}
    if(x =='^')
    {p=4;}
    if(x =='%')
    {p=3;}
    return p;
}
int opcheck(char k)
{
     if (k=='+'||k=='-'||k=='*'||k=='/'||k=='%'||k=='^')
     {return 1;}
     else 
     {return 0;}
}
void push(Stack1 *s, char x)
{
    if (!full(s))
    {
        s->top++;
        s->a[s->top] = x;
    }
}
char pop(Stack1 *s)
{
    char x;
    if (!empty(s))
    {
        x = s->a[s->top];
        s->top--;
    }
    return x;
}
void printst(Stack1 *s)
{
    if (!empty(s))
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%c", s->a[i]);
        }
    }
}
char peek(Stack1 *s)
{
    char x;
    if (!empty(s))
    {
        x = s->a[s->top];
    }
    return x;
}
int full(Stack1 * s)
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
int empty(Stack1 * s)
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