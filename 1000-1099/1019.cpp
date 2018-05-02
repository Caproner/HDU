#include<cstdio>
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    if(a==0&&b==0)return 0;
    return (a/gcd(a,b))*b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ans;
        scanf("%d%d",&n,&ans);
        for(int i=1;i<n;i++)
        {
            int p;
            scanf("%d",&p);
            ans=lcm(ans,p);
        }
        printf("%d\n",ans);
    }
}
