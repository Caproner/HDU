#include<stdio.h>
int main()
{    
    int n,m,i,j,a[50][5],c[50],d;
    double b;
    while(scanf("%d %d",&n,&m)==2)
    {
        d=0;
        for(i=0;i<n;i++)c[i]=1;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
        {
            b=0;
            for(j=0;j<m;j++)b+=(double)a[i][j];
            b/=m;
            if(i==0)printf("%.2lf",b);
            else printf(" %.2lf",b);
        }
        printf("\n");
                for(j=0;j<m;j++)
        {
            b=0;
            for(i=0;i<n;i++)b+=(double)a[i][j];
            b/=n;
            if(j==0)printf("%.2lf",b);
            else printf(" %.2lf",b);
            for(i=0;i<n;i++)if((double)a[i][j]<b)c[i]--;
        }
        printf("\n");
        for(i=0;i<n;i++)if(c[i]>0)d++;
        printf("%d\n\n",d);
    }
    return 0;
}
