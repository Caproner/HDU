#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int v[105];
int a[105];
int n,m;
vector<int> e[105];
bool vis[105];
void init()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<105;i++)
        e[i].clear();
    memset(vis,0,sizeof(vis));
}
void dfs(int p)
{
    for(int i=a[p];i<=m;i++)
        dp[p][i]=v[p];
    vis[p]=true;
    for(int i=0;i<e[p].size();i++)
    {
        int &pp=e[p][i];
        if(vis[pp])continue;
        dfs(pp);
        for(int j=m;j>=a[p];j--)
            for(int k=j-a[p];k>=1;k--)
                dp[p][j]=max(dp[p][j],dp[p][j-k]+dp[pp][k]);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2&&((n+1)||(m+1)))
    {
        init();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&v[i]);
            a[i]=(a[i]+19)/20;
        }
        for(int i=0;i<n-1;i++)
        {
            int uu,vv;
            scanf("%d%d",&uu,&vv);
            uu--;vv--;
            e[uu].push_back(vv);
            e[vv].push_back(uu);
        }
        if(m==0)
        {
            printf("0\n");
            continue;
        }
        dfs(0);
        printf("%d\n",dp[0][m]);
    }
}
