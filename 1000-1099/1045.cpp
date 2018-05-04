#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
struct Hopcroft_Karp
{
    int n1,n2,ans;
    vector<int> g[MAXN];
    int mx[MAXN],my[MAXN];
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
    void matching()
    {
        memset(mx,0,sizeof(mx));
        memset(my,0,sizeof(my));
        ans=0;
        while(true)
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
char mp[10][10];
int xx[10][10];
int yy[10][10];
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        int cnt=1;
        memset(xx,-1,sizeof(xx));
        memset(yy,-1,sizeof(yy));
        h.clear(n+5,n+5);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]=='X')cnt++;
                else xx[i][j]=cnt;
            }
            cnt++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[j][i]=='X')cnt++;
                else yy[j][i]=cnt;
            }
            cnt++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(xx[i][j]!=-1)
                    h.g[xx[i][j]].push_back(yy[i][j]);
            }
        }
        h.matching();
        printf("%d\n",h.ans);
    }
}
