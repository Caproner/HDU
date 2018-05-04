#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,w;
    node(){}
    node(int xx,int yy,int ww):x(xx),y(yy),w(ww){}
};
int vis[1005][1005];
node mp[1005][1005];
int n,m;
void solve(node s)
{
    memset(vis,0,sizeof(vis));
    while(true)
    {
        if(s.x<0||s.x>=n||s.y<0||s.y>=m)
        {
            printf("%d step(s) to exit\n",s.w-1);
            break;
        }
        if(vis[s.x][s.y]!=0)
        {
            printf("%d step(s) before a loop of %d step(s)\n",vis[s.x][s.y]-1,s.w-vis[s.x][s.y]);
            break;
        }
        vis[s.x][s.y]=s.w;
        node p=mp[s.x][s.y];
        s.x+=p.x;
        s.y+=p.y;
        s.w++;
    }
}
int main()
{
    char s[1005];
    while(scanf("%d%d",&n,&m)==2&&(n||m))
    {
        int k;
        scanf("%d",&k);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;j<m;j++)
            {
                if(s[j]=='W')mp[i][j]=node(0,-1,0);
                if(s[j]=='S')mp[i][j]=node(1,0,0);
                if(s[j]=='E')mp[i][j]=node(0,1,0);
                if(s[j]=='N')mp[i][j]=node(-1,0,0);
            }
        }
        solve(node(0,k-1,1));
    }
}
