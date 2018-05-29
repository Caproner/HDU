#include<cstdio>
long long c(int n,int a)
{
    long long ans=1;
    for(int i=1;i<=a;i++)
    {
        ans*=(n-i+1);
        ans/=i;
    }
    return ans;
}
int main()
{
    long long a[26],ans[26];
    a[0]=1;
    a[1]=0;
    a[2]=1;
    for(int i=3;i<=25;i++)
    {
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    }
    for(int i=1;i<=25;i++)
    {
        ans[i]=0;
        for(int j=0;j<=(i/2);j++)ans[i]+=(a[j]*c(i,j));
    }
    int n;
    while(scanf("%d",&n)==1&&n)printf("%lld\n",ans[n]);
}
