#include<stdio.h>
int main()
{
    int n,a[100],i,min,t;
    while(1)
    {
        min=0;
        scanf("%d",&n);
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<a[min])min=i;
        }
        t=a[0];
        a[0]=a[min];
        a[min]=t;
        for(i=0;i<n;i++)
        {
            if(i==0)printf("%d",a[i]);
            else printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
