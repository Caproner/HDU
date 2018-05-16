#include<bits/stdc++.h>
using namespace std;
struct BigInteger
{
    int a[1005];
    int n;
    void init(char *s,int len)
    {
        for(int i=len-1;i>=0;i--)
            a[len-i-1]=s[i]-'0';
        n=len;
    }
    BigInteger operator /(int p)
    {
        BigInteger ret;
        ret.n=0;
        int rmd=0;
        for(int i=n-1;i>=0;i--)
        {
            rmd*=10;
            rmd+=a[i];
            ret.a[ret.n++]=rmd/p;
            rmd%=p;
        }
        reverse(ret.a,ret.a+n);
        while(ret.a[ret.n-1]==0)ret.n--;
        return ret;
    }
//    void print()
//    {
//        for(int i=n-1;i>=0;i--)
//            printf("%d",a[i]);
//        printf("\n");
//    }
};
int solve(BigInteger a)
{
    if(a.n==1)
    {
        int ret=1;
        for(int i=1;i<=a.a[0];i++)
        {
            ret*=i;
            while(ret%10==0)ret/=10;
        }
        return ret%10;
    }
    int ret=solve(a/5);
    if(a.a[1]&1)ret*=4;
    else ret*=6;
    ret%=10;
    for(int i=1;i<=a.a[0];i++)
    {
        if(i==5)continue;
        if(i==2&&a.a[0]>=5)
        {
            if(a.a[1]&1)ret*=6;
        }
        else ret*=i;
        ret%=10;
    }
    return ret;
}
int main()
{
    char s[1005];
    while(scanf("%s",s)==1)
    {
        BigInteger a;
        a.init(s,strlen(s));
        printf("%d\n",solve(a));
    }
}
