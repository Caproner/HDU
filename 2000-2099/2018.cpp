#include<stdio.h>
int main()
{
    int n,a[54],i,k=1;
    a[0]=1;
    for(i=1;i<54;i++)
    {
        if(i<4)k=1;
        else k=a[i-3];
        a[i]=a[i-1]+k;
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        else printf("%d\n",a[n-1]);
    }
    return 0;
}
