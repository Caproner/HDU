#include<bits/stdc++.h>
using namespace std;
int vis[150][13][40];
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int y,int m,int d)
{
    if(y<101)return true;
    if(y>101)return false;
    if(m<11)return true;
    if(m>11)return false;
    return d<=4;
}
bool dfs(int y,int m,int d)
{
    if(vis[y][m][d]!=-1)return vis[y][m][d];
    bool ans=false;
    int yy=y,mm=m,dd=d;
    dd++;
    if(dd>days[mm])
    {
        if(!((mm==2)&&(yy%4==0)&&(yy!=0)&&(dd==29)))
        {
            dd=1;
            mm++;
            if(mm>12)
            {
                mm=1;
                yy++;
            }
        }
    }
    if(check(yy,mm,dd))
        if(!dfs(yy,mm,dd))ans=true;
    yy=y;
    mm=m;
    dd=d;
    mm++;
    if(mm>12)
    {
        mm=1;
        yy++;
    }
    if(dd<=days[mm]||((mm==2)&&(yy%4==0)&&(yy==0)&&(dd==29)))
        if(check(yy,mm,dd))
            if(!dfs(yy,mm,dd))ans=true;
    if(ans)vis[y][m][d]=1;
    else vis[y][m][d]=0;
    return ans;
}
int main()
{
    int y,m,d,t;
    memset(vis,-1,sizeof(vis));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        y-=1900;
        if(dfs(y,m,d))printf("YES\n");
        else printf("NO\n");
    }
}
