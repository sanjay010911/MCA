/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main() {
    char word1[]="abcd";
    char word2[]="pq";
    char str[100];
    int flag=0,i=0,j=0,k=0;
    while(word1[i]!='\0'&&word2[j]!='\0')
    {
        if(flag==0)
        {
            str[k]=word1[i];
            flag=1;
            i++;
            k++;
        }
        else if(flag==1)
        {
            str[k]=word2[j];
            flag=0;
            j++;
            k++;
        }
    }
    if(word1[i]=='\0')
    {
        while(word2[j]!='\0')
        {
            str[k]=word2[j];
            j++;
            k++;
        }
    }
else
    while(word1[i]!='\0')
        {
            str[k]=word1[i];
            i++;
            k++;
        }
    printf("%s",str);

    return 0;
}
