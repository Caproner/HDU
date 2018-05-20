#include<stdio.h>
#include<math.h>
int main()
{
    int m,i;
    double n,ans;
    while(scanf("%lf %d",&n,&m)==2)
    {
        ans=0;
        for(i=0;i<m;i++)
        {
            ans+=n;
            n=sqrt(n);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
