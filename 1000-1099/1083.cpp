#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 1005
using namespace std;
struct Hopcroft_Karp
{
    int n1,n2,ans;//n1为左边的点数，n2为右边的点数，ans为最大匹配数
    vector<int> g[MAXN];//g[i]表示与左边点i相连的右边的点
    int mx[MAXN],my[MAXN];//mx[i]表示最大匹配中与左边点i相连的点，my[i]表示最大匹配中与右边点i相连的点。
    int dx[MAXN],dy[MAXN];
    bool vis[MAXN];
    queue<int> q;
    bool find(int u)
    {
        for(int i=0;i<g[u].size();i++)
        {
            if(!vis[g[u][i]]&&dy[g[u][i]]==dx[u]+1)
            {
                vis[g[u][i]]=true;
                if(!my[g[u][i]]||find(my[g[u][i]]))
                {
                    mx[u]=g[u][i];
                    my[g[u][i]]=u;
                    return true;
                }
            }
        }
        return false;
    }
    void matching()//跑完这个函数之后便可以从结构体中提取所需要的答案
    {
        memset(mx,0,sizeof(mx));
        memset(my,0,sizeof(my));
        ans=0;
        while(1)
        {
            bool flag=false;
            while(!q.empty())q.pop();
            memset(dx,0,sizeof(dx));
            memset(dy,0,sizeof(dy));
            for(int i=1;i<=n1;i++)
                if(!mx[i])q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int i=0;i<g[u].size();i++)
                {
                    if(!dy[g[u][i]])
                    {
                        dy[g[u][i]]=dx[u]+1;
                        if(my[g[u][i]])
                        {
                            dx[my[g[u][i]]]=dy[g[u][i]]+1;
                            q.push(my[g[u][i]]);
                        }
                        else flag=true;
                    }
                }
            }
            if(!flag)break;
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=n1;i++)
                if(!mx[i]&&find(i))ans++;
        }
    }
    void clear(int nn1,int nn2)
    {
        n1=nn1;
        n2=nn2;
        for(int i=1;i<=n1;i++)
            g[i].clear();
    }
}h;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p,n;
        scanf("%d%d",&p,&n);
        h.clear(p,n);
        for(int i=1;i<=p;i++)
        {
            int m,pp;
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&pp);
                h.g[i].push_back(pp);
            }
        }
        h.matching();
        if(p==h.ans)printf("YES\n");
        else printf("NO\n");
    }
}
