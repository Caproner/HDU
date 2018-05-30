#include<stdio.h>
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        double a,an,c[3000];
        scanf("%lf %lf",&a,&an);
        for(int i=0;i<n;i++)scanf("%lf",&c[i]);
        double ans=n*a/(n+1)+an/(n+1);
        double cm=0;
        for(int i=2,j=n-1;j>=0;j--,i+=2)cm+=(double)i*c[j];
        cm=cm/(n+1);
        ans-=cm;
        printf("%.2lf\n",ans);
    }
}
