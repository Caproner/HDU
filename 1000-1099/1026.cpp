#include<bits/stdc++.h>
using namespace std;
char mp[205][205];
int n,m;
struct node
{
    int x,y;
    int prx,pry;
    int w;
    node(){}
    node(int xx,int yy,int xxx,int yyy,int ww):x(xx),y(yy),prx(xxx),pry(yyy),w(ww){}
    void init()
    {
        x=y=w=prx=pry=-1;
    }
    bool operator <(const node &a)const
    {
        return a.w<w;
    }
};
int tur[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
node vis[205][205];
int bfs()
{
    priority_queue<node> q;
    q.push(node(0,0,-1,-1,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            vis[i][j].init();
    while(!q.empty())
    {
        node p=q.top();
        q.pop();
        if(vis[p.x][p.y].x!=-1)continue;
        vis[p.x][p.y]=p;
        if(p.x==n-1&&p.y==m-1)return p.w;
        for(int i=0;i<4;i++)
        {
            node pp=p;
            pp.x+=tur[i][0];
            pp.y+=tur[i][1];
            pp.w++;
            pp.prx=p.x;
            pp.pry=p.y;
            if(pp.x<0||pp.y<0||pp.x>=n||pp.y>=m||vis[pp.x][pp.y].x!=-1||mp[pp.x][pp.y]=='X')continue;
            if(mp[pp.x][pp.y]!='.')pp.w+=(mp[pp.x][pp.y]-'0');
            q.push(pp);
        }
    }
    return -1;
}
node stk[40005];
int top;
void solve()
{
    int ans=bfs();
    if(ans==-1)
    {
        printf("God please help our poor hero.\n");
    }
    else
    {
        top=0;
        node p=vis[n-1][m-1];
        printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
        while(p.prx!=-1)
        {
            stk[top++]=p;
            p=vis[p.prx][p.pry];
        }
        stk[top++]=p;
        int cnt=1;
        for(top--;top>=0;top--)
        {
            if(stk[top].prx!=-1)
            {
                printf("%ds:(%d,%d)->(%d,%d)\n",cnt++,stk[top].prx,stk[top].pry,stk[top].x,stk[top].y);
            }
            if(mp[stk[top].x][stk[top].y]!='.')
            {
                for(int i=0;i<mp[stk[top].x][stk[top].y]-'0';i++)
                {
                    printf("%ds:FIGHT AT (%d,%d)\n",cnt++,stk[top].x,stk[top].y);
                }
            }
        }
    }
    printf("FINISH\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        solve();
    }
}
