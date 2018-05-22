#include<stdio.h>
int main()
{
    int n,m,a[100],b[100],c[100],i,j,p,k;
    while(1)
    {
        p=1;
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)break;
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=0;i<m;i++)scanf("%d",&b[i]);
        for(i=0;i<n;i++)c[i]=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i]==b[j])
                {
                    c[i]=0;
                    break;
                }
            }
        }
        k=0;
        for(i=0;i<n;i++)if(c[i]){c[k]=a[i];k++;p=0;}
        int min,t;
        for(i=0;i<k;i++)
        {
            min=i;
            for(j=i;j<k;j++)
            if(c[j]<c[min])min=j;
            t=c[min];
            c[min]=c[i];
            c[i]=t;
        }
        if(p)printf("NULL");
        else
        {
            for(i=0;i<k;i++)printf("%d ",c[i]);
        }
        printf("\n");
    }
}
