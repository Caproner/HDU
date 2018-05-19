#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
struct node
{
    long long a,b;
    node(){}
    node(long long aa,long long bb):a(aa),b(bb){}
    node operator +(node p)
    {
        node res=p;
        long long k=gcd(b,p.b);
        p.b*=(b/k);
        p.a*=(b/k);
        b*=(res.b/k);
        a*=(res.b/k);
        res.b=b;
        res.a=a+p.a;
        k=gcd(res.a,res.b);
        res.a/=k;
        res.b/=k;
        return res;
    }
    void print()
    {
        if(a%b==0)
        {
            printf("%lld\n",a/b);
            return;
        }
        long long k=a/b;
        a=a%b;
        long long p=k;
        int cnt=0,cntt=0;
        while(p)
        {
            cnt++;
            p/=10;
        }
        for(int i=0;i<=cnt;i++)printf(" ");
        printf("%lld\n",a);
        printf("%lld ",k);
        p=b;
        while(p)
        {
            cntt++;
            p/=10;
        }
        for(int i=0;i<cntt;i++)printf("-");
        printf("\n");
        for(int i=0;i<=cnt;i++)printf(" ");
        printf("%lld\n",b);
    }
};
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        node ans=node(1,1);
        for(int i=1;i<n;i++)
        {
            ans=ans+node(n,n-i);
        }
        ans.print();
    }
}
