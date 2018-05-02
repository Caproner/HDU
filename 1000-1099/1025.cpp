#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
    int c,a;
};
bool comp(point a,point b)
{
    return a.c<b.c;
}
point b[500005];
int find(int x,int len)
{
    int l=0,r=len,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(x>=b[mid].c)l=mid+1;
        else r=mid-1;
    }
    return l;
}
int solve(int n)
{
    for(int i=0;i<n;i++)b[i].c=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        int k=find(b[i].a,len);
        b[k].c=b[i].a;
        if(len<k)len=k;
    }
    return len;
}
int main()
{
    int n,cas=1;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&b[i].a,&b[i].c);
        }
        sort(b,b+n,comp);
        int ans=solve(n);
        printf("Case %d:\n",cas++);
        if(ans==1)printf("My king, at most 1 road can be built.\n");
        else printf("My king, at most %d roads can be built.\n",ans);
        printf("\n");
    }
}
