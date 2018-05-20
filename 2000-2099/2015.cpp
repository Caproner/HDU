#include<stdio.h>
int main()
{
    int n,m,i,j,t,ans;
    while(scanf("%d %d",&n,&m)==2)
    {
        t=1;
        for(i=0;i<(n/m);i++)
        {
            ans=0;
            for(j=t;j<m+t;j++)ans+=(j*2);
            ans=ans/m;
            if(i==0)printf("%d",ans);
            else printf(" %d",ans);
            t+=m;
        }
        ans=0;
        if(t<n+1)
        {
        for(j=t;j<n+1;j++)ans+=(j*2);
        ans=ans/(n+1-t);
        printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}
