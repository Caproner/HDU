#include<bits/stdc++.h>
using namespace std;
bool vis[55][55][1024];
char mp[55][55];
int wk[10];
int n,m,lmt,l;
struct node
{
    int x,y,z;
    int w,t;
};
queue<node> q;
int ans;
int tur[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void bfs(node s)
{
    ans=-1;
    while(!q.empty())q.pop();
    memset(vis,0,sizeof(vis));
    vis[s.x][s.y][s.z]=true;
    q.push(s);
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
    //    printf("(%d,%d)[%d]: %d %d\n",p.x,p.y,p.z,p.w,p.t);
        if(mp[p.x][p.y]=='<')
        {
            if(ans<p.w)ans=p.w;
        }
        if(p.t==lmt)continue;
        for(int i=0;i<4;i++)
        {
            node pp=p;
            pp.x+=tur[i][0];
            pp.y+=tur[i][1];
    //        printf("%d %d\n",pp.x,pp.y);
            if(pp.x<0||pp.y<0||pp.x>=n||pp.y>=m)continue;
            if(mp[pp.x][pp.y]=='*')continue;
            if(mp[pp.x][pp.y]>='A'&&mp[pp.x][pp.y]<='J')
            {
                int ck=1;
                for(int i='A';i<mp[pp.x][pp.y];i++)
                    ck<<=1;
                if(!(pp.z&ck))
                {
                    pp.z+=ck;
                    pp.w+=wk[mp[pp.x][pp.y]-'A'];
                }
            }
            if(vis[pp.x][pp.y][pp.z])continue;
            vis[pp.x][pp.y][pp.z]=true;
            pp.t++;
            q.push(pp);
        }
    }
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&m,&n,&lmt,&l);
        for(int i=0;i<l;i++)
            scanf("%d",&wk[i]);
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        node s;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mp[i][j]=='@')
                {
                    s.x=i;
                    s.y=j;
                    s.z=0;
                    s.w=0;
                    s.t=0;
                }
        bfs(s);
        printf("Case %d:\n",cas++);
        if(ans==-1)printf("Impossible\n");
        else printf("The best score is %d.\n",ans);
        if(t)printf("\n");
    }
}
