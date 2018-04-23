#include<cstdio>
#include<cmath>
char a[10][10];
int b[10][10],t,n,m,ok;
int check(int x,int y,int p)
{
    if(ok)return ok;
    int ans;
    if(x<0||x>=n||y<0||y>=m||p>t)return 0;
    if(a[x][y]=='X'||b[x][y]==1)return 0;
    if(t==p&&a[x][y]!='D')return 0;
    b[x][y]=1;
    if(a[x][y]=='D')
    {
        if(t==p)
        {
            ans=1;
            ok=1;
        }
        else ans=0;
    }
    else ans=check(x+1,y,p+1)||check(x-1,y,p+1)||check(x,y+1,p+1)||check(x,y-1,p+1);
    b[x][y]=0;
    return ans;
}
int main()
{
    //freopen("data.in","r",stdin);
    while(scanf("%d %d %d",&n,&m,&t)==3&&(n||m||t))
    {
        int c=0;
        ok=0;
        getchar();
        int x,y,dx,dy;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&a[i][j]);
                if(a[i][j]=='S')
                {
                    x=i;
                    y=j;
                }
                if(a[i][j]=='D')
                {
                    dx=i;
                    dy=j;
                }
                if(a[i][j]=='.')c++;
                b[i][j]=0;
            }
            getchar();
        }
        int ans;
        if(t>c+1)ans=0;
        else if(abs(dx+dy-x-y)%2!=t%2)ans=0;
        else ans=check(x,y,0);
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
}
