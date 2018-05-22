//Code by Caproner

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL d[30];

LL f[30];

void init()
{
    d[1]=0;
    d[2]=1;
    f[1]=1;
    f[2]=2;
    for(int n=3;n<=20;n++)
    {
        d[n]=(d[n-2]+d[n-1])*(n-1);
        f[n]=f[n-1]*n;
    }
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        double ans=d[n];
        ans*=100;
        ans/=f[n];
        printf("%.2lf%%\n",ans);
    }
    return 0;
}
