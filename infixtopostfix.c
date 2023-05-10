#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int prec(char x);

int opcheck(char k);

typedef struct stk
{
    int top;
    // int size;
    char a[30];

} Stack2;

void push(Stack2 *s, char x);
char pop(Stack2 *s);
void printst(Stack2 *s);
char peek(Stack2 *s);
int full(Stack2 *s);
int empty(Stack2 *s);

void main()
{
    Stack2 ms;
    ms.top = -1;

    //(a+b*c)-(d+e/f)

    // L-bracket push
    // opernd push
    // opretor pop higher priority && push operetor
    // R-brcket pop all

    char str[] = "(a+b*c)-(d+e/f)";
    char out[100];
    int i = 0, j = 0;
    while (str[i] != '\0')
    {

        char c = str[i];
     
        if (c == '(') // L bracket
        {
            push(&ms, c);
        }

        if (isalpha(c)) // operand
        {
            out[j] = c;
            j++;
        }

        if (opcheck(c)) // operator
        {
            while (prec(c) <= prec(ms.a[ms.top]))
            {
                char k = pop(&ms);
                out[j] = k;
                j++;
            }
            push(&ms, c);
        }

        if (c == ')') // R- bracket
        {
            char k ;
            do
            {
                k = pop(&ms);
                {
                    if (opcheck(k))
                        out[j] = k;
                    j++;
                }
            } while (ms.a[ms.top] != '(');
        }

        i++;
    }
    i = 0;
    while (out[i] != '\0')
    {
        printf("%c", out[i]);
        i++;
    }
}

int prec(char x)
{
    int p;
    if (x == '+')
    {
        p = 1;
    }
    if (x == '-')
    {
        p = 0;
    }
    if (x == '*')
    {
        p = 3;
    }
    if (x == '/')
    {
        p = 4;
    }
    if (x == '^')
    {
        p = 6;
    }
    return p;
}
int opcheck(char k)
{
    if (k == '+' || k == '-' || k == '*' || k == '/' || k == '%' || k == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(Stack2 *s, char x)
{
    if (!full(s))
    {
        s->top++;
        s->a[s->top] = x;
    }
}
char pop(Stack2 *s)
{
    char x;
    if (!empty(s))
    {
        x = s->a[s->top];
        s->top--;
    }
    return x;
}
void printst(Stack2 *s)
{
    if (!empty(s))
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%c", s->a[i]);
        }
    }
}
char peek(Stack2 *s)
{
    char x;
    if (!empty(s))
    {
        x = s->a[s->top];
    }
    return x;
}
int full(Stack2 *s)
{
    if (s->top == 29)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int empty(Stack2 *s)
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