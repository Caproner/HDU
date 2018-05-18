#include<bits/stdc++.h>
using namespace std;
int mp[10][10];
int n,m;
bool vis[10][10][10];
int tur[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node
{
    int x,y,t;
    int w;
};
int solve(node s,int tx,int ty)
{
    queue<node> q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    vis[s.x][s.y][s.t]=true;
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
        if(p.x==tx&&p.y==ty)return p.w;
        for(int i=0;i<4;i++)
        {
            node pp=p;
            pp.t--;
            pp.x+=tur[i][0];
            pp.y+=tur[i][1];
            if(pp.x<0||pp.y<0||pp.x>=n||pp.y>=m||pp.t==0||mp[pp.x][pp.y]==0)continue;
            if(mp[pp.x][pp.y]==4)pp.t=6;
            pp.w++;
            if(vis[pp.x][pp.y][pp.t])continue;
            vis[pp.x][pp.y][pp.t]=true;
            q.push(pp);
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        node s;
        s.t=6,s.w=0;
        int tx,ty;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                scanf("%d",&mp[i][j]);
                if(mp[i][j]==2)
                {
                    s.x=i;
                    s.y=j;
                }
                if(mp[i][j]==3)
                {
                    tx=i;
                    ty=j;
                }
            }
        printf("%d\n",solve(s,tx,ty));
    }
}
