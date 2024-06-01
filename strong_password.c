#include<stdio.h>
#include<string.h>
#define MAX 100

int function(char * str)
{
   int cap=0, small=0, dig=0, space=1, nonalpha=0, i;
   
   
   for(i=0; str[i]!='\0'; i++) 
   {
       if(str[i]>='a' && str[i]<='z')
           small=1;
       else if(str[i]>='A' && str[i]<='Z')
           cap=1;
       else if(str[i]>='0' && str[i]<='9')
           dig=1;
       else if(str[i]==' ')
           space=0;
       else 
           nonalpha=1;
   }

  
   if(strlen(str) < 8)
       return 0;
   
   
   if(cap==1 && small==1 && dig==1 && nonalpha==1 && space==1)
       return 1;
   else
       return 0;
}

int main()  
{   
    char text[MAX];
    
    if (fgets(text, sizeof(text), stdin) != NULL) {
        
        size_t len = strlen(text);
        if (len > 0 && text[len-1] == '\n') {
            text[len-1] = '\0';
        }
        int out = function(text);
        printf("%d\n", out);  
    }
    
    return 0;
}
