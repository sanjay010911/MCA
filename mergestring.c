#include <stdio.h>
#include<string.h>
void main()
{
    char word1[]="abcde", word2[]="pq",res[100];
    int i=0,j=0,k,len1,len2;
    len1=strlen(word1);
    len2=strlen(word2);
    for(k=0; k < len1+len2; )
    {
        if(word1[i]!= '\0')
            res[k++]=word1[i++];
        if(word2[j]!= '\0')
            res[k++]=word2[j++];
    }
    res[k]='\0';
    printf("%s",res);
}