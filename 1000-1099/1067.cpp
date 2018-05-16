#include<bits/stdc++.h>
using namespace std;
const long long mod=999997;
struct node
{
    int mp[4][8];
    int nxt[4][8][2];
    int blk[4][2];
    int w,ck;
};
long long hhash(node s)
{
    long long p=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<8;j++)
        {
            p*=50;
            p+=s.mp[i][j];
            p%=mod;
        }
    return p;
}
bool vis[1000005];
queue<node> q;
int bfs(node s)
{
    while(!q.empty())q.pop();
    q.push(s);
    memset(vis,0,sizeof(vis));
    vis[hhash(s)]=true;
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
/*        for(int i=0;i<4;i++)
        {
            for(int j=0;j<8;j++)
                printf("%d\t",p.mp[i][j]);
            printf("\n");
        }
        system("pause");*/
        if(p.ck==28)return p.w;
        for(int i=0;i<4;i++)
        {
            int &x=p.blk[i][0];
            int &y=p.blk[i][1];
            if(p.mp[x][y-1]==0||p.mp[x][y-1]%10==7)continue;
            node pp=p;
            int &xx=p.nxt[x][y-1][0];
            int &yy=p.nxt[x][y-1][1];
            if(pp.mp[xx][yy]%10==yy+1&&pp.mp[xx][yy]/10==xx+1)pp.ck--;
            swap(pp.mp[x][y],pp.mp[xx][yy]);
            if(vis[hhash(pp)])continue;
            vis[hhash(pp)]=true;
            swap(pp.nxt[x][y][0],pp.nxt[xx][yy][0]);
            swap(pp.nxt[x][y][1],pp.nxt[xx][yy][1]);
            pp.blk[i][0]=xx;
            pp.blk[i][1]=yy;
            pp.nxt[x][y-1][0]=x;
            pp.nxt[x][y-1][1]=y;
            pp.w++;
            if(pp.mp[x][y]%10==y+1&&pp.mp[x][y]/10==x+1)pp.ck++;
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
        node s;
        int cnt=0;
        for(int i=0;i<4;i++)
            for(int j=0;j<7;j++)
            {
                scanf("%d",&s.mp[i][j+1]);
                if(s.mp[i][j+1]%10==1)
                {
                    s.mp[i][j+1]=0;
                    s.blk[cnt][0]=i;
                    s.blk[cnt][1]=j+1;
                    cnt++;
                }
            }
        for(int i=0;i<4;i++)
            s.mp[i][0]=(i+1)*10+1;
        s.w=0;
        s.ck=0;
        for(int i=0;i<4;i++)
            for(int j=0;j<8;j++)
                if(s.mp[i][j]%10==j+1&&s.mp[i][j]/10==i+1)s.ck++;
        for(int i=0;i<4;i++)
            for(int j=0;j<8;j++)
            {
                if(s.mp[i][j]==0)continue;
                for(int ii=0;ii<4;ii++)
                    for(int jj=0;jj<8;jj++)
                        if(s.mp[ii][jj]==s.mp[i][j]+1)
                        {
                            s.nxt[i][j][0]=ii;
                            s.nxt[i][j][1]=jj;
                        }
            }
        printf("%d\n",bfs(s));
    }
}
