#include <stdio.h>
#include<string.h>
char o[40];
int pos=-1;
void push(char a)
{
    if(pos!=9)
    {
        ++pos;
        o[pos]=a;
    }
    else
        printf("stack is full\n");
}
int precedence(char operator)
{
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void pop()
{
    if(pos!=-1)
    {
        char c=o[pos];
        pos--;
        //return c;
    }
    else
    printf("stack underfow\n");
    
}

 int op[10];
   
void push2(int a)
{
    if(pos!=9)
    {
        //++pos;
        op[pos]=a;
    }
    else
        printf("stack is full\n");
}
int main()
{
    char a[30],d[30];
    int i,j;
    
    printf("enter a string\n");
    scanf("%s",a);
    
    for(i=0,j=0;i<strlen(a);i++)
    {
        switch(a[i])
        {
            case '(':push(a[i]);
                        break;
            case ')':while(o[pos]!='(')
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    pop();
                    break;
            case '+':while((pos!=-1)&&(o[pos]!='(')&&(precedence(a[i])<=precedence(o[pos])))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            case '-':while((pos!=-1)&&(o[pos]!='(')&&(precedence(a[i])<=precedence(o[pos])))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            case '*':while((pos!=-1)&&(o[pos]!='(')&&(precedence(a[i])<=precedence(o[pos])))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            case '/':while((pos!=-1)&&(o[pos]!='(')&&(precedence(a[i])<=precedence(o[pos])))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            case '=':while((pos!=-1)&&(o[pos]!='(')&&(precedence(a[i])<=precedence(o[pos])))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            default:d[j]=a[i];
                    j++;
                    break;
        }
    }
    while(pos!=-1)
    {
        d[j]=o[pos];
        pop();
    }
    
    printf("Postfix is : %s",d);
    
    
    int c,v,r;
    pos=-1;
  
   
    
    for(i=0;i<strlen(d);i++)
    {
        switch(d[i])
        {
            case '+':
                    c=op[pos];
                    pos--;
                    v=op[pos];
                    push2(v+c);
                    break;
            case '-':
                    c=op[pos];
                     pos--;
                    v=op[pos];
                    push2(v-c);
                    break;
            case '*':
                    c=o[pos];
                    pos--;
                    v=op[pos];
                    push2(v*c);
                    break;
            case '/':
                    c=o[pos];
                    pos--;
                    v=op[pos];
                    push2(v/c);
                    break;
            default:pos++;
                    r=d[i]-'0';
                    push2(r);
                    break;
        }
    }
     printf("result is : %d",op[pos]);
    return 0;
}

