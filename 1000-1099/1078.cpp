#include<bits/stdc++.h>
using namespace std;
int mp[105][105];
int ans[105][105];
int tur[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,k;
int dfs(int x,int y)
{
    ans[x][y]=mp[x][y];
    int pans=0;
    for(int i=0;i<4;i++)
    {
        int px=x,py=y;
        for(int j=0;j<k;j++)
        {
            px+=tur[i][0];
            py+=tur[i][1];
            if(px<0||py<0||px>=n||py>=n)break;
            if(mp[px][py]<=mp[x][y])continue;
            if(ans[px][py]==-1)dfs(px,py);
            if(pans<ans[px][py])pans=ans[px][py];
        }
    }
    ans[x][y]+=pans;
    return ans[x][y];
}
int main()
{
    while(scanf("%d%d",&n,&k)==2&&((n+1)||(k+1)))
    {
        memset(ans,-1,sizeof(ans));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mp[i][j]);
        printf("%d\n",dfs(0,0));
    }
}
