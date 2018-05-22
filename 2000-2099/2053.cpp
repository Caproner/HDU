#include<stdio.h>
int main()
{
    int a,i,p;
    while(scanf("%d",&a)==1)
    {
        p=0;
        for(i=1;i<a+1;i++)
        {
            if(a%i==0)p=!p;
        }
        printf("%d\n",p);
    }
}
