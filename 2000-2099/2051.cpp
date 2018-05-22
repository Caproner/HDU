#include<stdio.h>
int main()
{
    int n,a[50],p,i;
    while(scanf("%d",&n)==1)
    {
        p=0;
        while(n)
        {
            a[p]=n%2;
            n/=2;
            p++;
        }
        for(i=p;i>0;i--)printf("%d",a[i-1]);
        printf("\n");
    }
}
