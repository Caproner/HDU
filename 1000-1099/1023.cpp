#include<bits/stdc++.h>
using namespace std;
struct BigInteger
{
    int a[60];
    int len;
    BigInteger()
    {
        memset(a,0,sizeof(a));
        len=1;
    }
    BigInteger(int n)
    {
        memset(a,0,sizeof(a));
        len=0;
        while(n)
        {
            a[len++]=n%10;
            n/=10;
        }
        if(len==0)len=1;
    }
    void print()
    {
        for(int i=len-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    BigInteger operator +(BigInteger b)
    {
        BigInteger ret=b;
        for(int i=0,p=0;i<len||i<ret.len||p;i++)
        {
            ret.a[i]+=(a[i]+p);
            p=ret.a[i]/10;
            ret.a[i]%=10;
            if(i==ret.len)ret.len++;
        }
        return ret;
    }
    BigInteger operator *(int b)
    {
        BigInteger ret=*this;
        for(int i=0,p=0;i<ret.len||p;i++)
        {
            ret.a[i]*=b;
            ret.a[i]+=p;
            p=ret.a[i]/10;
            ret.a[i]%=10;
            if(i==ret.len)ret.len++;
        }
        return ret;
    }
    BigInteger operator *(BigInteger b)
    {
        BigInteger ret,p[10];
        p[0]=0;
        for(int i=1;i<10;i++)
            p[i]=p[i-1]+*this;
        for(int i=0;i<b.len;i++)
        {
            ret=ret+p[b.a[i]];
            for(int i=1;i<10;i++)
                p[i]=p[i]*10;
        }
        return ret;
    }
};
BigInteger h[105];
void init()
{
    h[0]=1;
    h[1]=1;
    for(int i=2;i<=100;i++)
    {
        h[i]=0;
        for(int j=0;j<i;j++)
            h[i]=h[i]+(h[j]*h[i-j-1]);
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)==1)
        h[n].print();
}
