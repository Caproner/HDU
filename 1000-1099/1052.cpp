#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int n;
int dp[1005][1005];
bool vis[1005][1005];
int dfs(int ap,int bp)
{
    if(vis[ap][bp])return dp[ap][bp];
    if(bp==n)return ap-n;
    int pingb=bp;
    vis[ap][bp]=true;
    while(pingb<n&&a[ap]<b[pingb])pingb++;
    if(pingb==n)return dp[ap][bp]=ap-n;
    if(a[ap]>b[pingb])return dp[ap][bp]=1+dfs(ap+1,pingb+1);
    int yingb=pingb;
    while(yingb<n&&a[ap]==b[yingb])yingb++;
    if(yingb==n)return dp[ap][bp]=dfs(ap+1,pingb+1);
    return dp[ap][bp]=max(dfs(ap+1,pingb+1),dfs(ap+1,yingb+1)+1);
}
int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        reverse(a,a+n);
        reverse(b,b+n);
        printf("%d\n",200*dfs(0,0));
    }
}