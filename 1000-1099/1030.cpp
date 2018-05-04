#include<bits/stdc++.h>
using namespace std;
int a[40000];
void init()
{
    for(int i=0;i<40000;i++)
        a[i]=i*i;
}
int solve(int n,int m)
{
    if(n>m)swap(n,m);
    int p1=lower_bound(a,a+40000,n)-a;
    int p2=lower_bound(a,a+40000,m)-a;
    if(p1==p2)return m-n;
    int l=n,r=n;
    int ans=0;
    if((p1&1)!=(n&1))
    {
        l--;
        r++;
        ans++;
    }
    while(p1<p2)
    {
        l+=(p1*2);
        r+=(p1*2);
        l--;
        r++;
        p1++;
        ans+=2;
    }
    if(l<=m&&m<=r)
    {
        if((l&1)!=(m&1))ans--;
        return ans;
    }
    if(m<l)return ans+l-m;
    return ans+m-r;
}
int main()
{
    init();
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        printf("%d\n",solve(n,m));
    }
}
