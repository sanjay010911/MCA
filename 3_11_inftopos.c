/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
char o[10];
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
int main()
{
    char a[10],d[10];
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
                    pos--;
                    break;
            case '+':while((pos!=-1)&&(o[pos]!='(')&&(a[i]<=o[pos]))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            case '-':while((pos!=-1)&&(o[pos]!='(')&&(a[i]<=o[pos]))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            case '*':while((pos!=-1)&&(o[pos]!='(')&&(a[i]<=o[pos]))
                    {
                        d[j]=o[pos];
                        pop();
                        j++;
                    }
                    push(a[i]);
                    break;
            case '/':while((pos!=-1)&&(o[pos]!='(')&&(a[i]<=o[pos]))
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
    return 0;
}

