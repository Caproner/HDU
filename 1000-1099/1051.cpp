#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,w;
    bool operator <(const node &a)const
    {
        if(a.l!=l)return l<a.l;
        return w<a.w;
    }
};
node a[5005];
bool vis[5005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].l,&a[i].w);
        sort(a,a+n);
    //    for(int i=0;i<n;i++)
    //        printf("%d %d\n",a[i].l,a[i].w);
        int ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            vis[i]=true;
            ans++;
            int p=i;
            for(int j=i+1;j<n;j++)
            {
                if(vis[j])continue;
                if(a[p].w<=a[j].w)
                {
                    p=j;
                    vis[p]=true;
                }
            }
        }
        printf("%d\n",ans);
    }
}