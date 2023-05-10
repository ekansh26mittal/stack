#include<stdio.h>
#include<math.h>
#include<ctype.h>


typedef struct stk
{
    int top;
    // int size;
    char a[30];

} Stack1;

void push(Stack1 *s, char x);
char pop(Stack1 *s);
void printst(Stack1 *s);
char peek(Stack1 *s);
int full(Stack1 *s);
int empty(Stack1 *s);


void main()
{
     Stack1  smain;

      char str[]="2 3 4 * + 5 -";

      int i=0;
    int k; 
     while(str[i]!='\0')
      {
        char c = str[i];
       if(c==' ')
       {
         i++;
         break;
       }
       if(isdigit(c))
       {
        push(c);

       }
       if()

        i++;
      }
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
