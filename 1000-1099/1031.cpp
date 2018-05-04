#include<bits/stdc++.h>
using namespace std;
struct node
{
    int i;
    double w;
    bool operator <(const node &a)const
    {
        if(a.w!=w)return a.w<w;
        return i<a.i;
    }
};
node a[100005];
int ans[100005];
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        for(int i=0;i<m;i++)
        {
            a[i].i=i+1;
            a[i].w=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                double ww;
                scanf("%lf",&ww);
                a[j].w+=ww;
            }
        }
        sort(a,a+m);
        for(int i=0;i<k;i++)
            ans[i]=a[i].i;
        sort(ans,ans+k);
        for(int i=k-1;i>=0;i--)
        {
            printf("%d",ans[i]);
            if(i!=0)printf(" ");
        }
        printf("\n");
    }
}
