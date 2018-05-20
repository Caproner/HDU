#include<stdio.h>
int main()
{
    int n,m,a[101],i,p;
    while(1)
    {
        p=0;
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)break;
        for(i=0;i<n+1;i++)
        {
            if(i==n&&p==0)a[i]=m;
            else scanf("%d",&a[i]);
            if(a[i]>m&&p==0)
            {
                a[i+1]=a[i];
                a[i]=m;
                p=1;
                i++;
            }
        }
        for(i=0;i<n+1;i++)
        {
            if(i==0)printf("%d",a[i]);
            else printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
