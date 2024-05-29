/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a[5],lar,sec,i;
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);
        
        
    if(a[0]>a[1]){
        lar=a[0];sec=a[1];
    }
    else
    {
        lar=a[1];sec=a[0];
    }
    for(i=2;i<5;i++)
    {
        if(a[i]>lar){
            sec=lar;
            lar=a[i];
        }
        else if(a[i]>sec)
            sec=a[i];
            
    }
    // max1=a[0];
    // for(i=1;i<5;i++)
    // {
    //     if(max1<a[i])
    //         max1=a[i];
    // }
    // max2=a[0];
    // for(i=1;i<5;i++)
    // {
    //     if(max2<a[i]&&a[i]<max1)
    //         max2=a[i];
    // }
    
    // printf("\nFirst largest: %d",max1);
    printf("\n%d",sec);

    return 0;
}
