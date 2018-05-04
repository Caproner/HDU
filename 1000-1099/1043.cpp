#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
    int a[3][3];
    int x,y;
    long long hash;
    long long f,g,h;
    void caclu()
    {
        hash=0;
        h=0;
        int k=1*2*3*4*5*6*7*8,kk=8;
        bool vis[10]={0};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int p=0;
                for(int ii=1;ii<10;ii++)
                {
                    if(ii==a[i][j])break;
                    if(!vis[ii])p++;
                }
                hash+=p*k;
                vis[a[i][j]]=true;
                if(kk!=0)
                {
                    k/=kk;
                    kk--;
                }
                int px=(a[i][j]-1)/3,py=(a[i][j]-1)%3;
                px-=i;
                py-=j;
                if(px<0)px=-px;
                if(py<0)py=-py;
                h+=(px+py);
            }
        }
        f=h*100+g;
    }
    bool operator <(const node &aa)const
    {
        return aa.f<f;
    }
};
struct nd
{
    long long w;
    char c;
    nd(){}
    nd(long long ww,char cc):w(ww),c(cc){}
};
int tur[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char ch[5]="rldu";
nd mp[400005];
priority_queue<node> q;
char ans[1000005];
int top;
void Astar(node s)
{
    for(int i=0;i<362880;i++)
        mp[i]=nd(-2,'0');
    while(!q.empty())q.pop();
    q.push(s);
    mp[s.hash]=nd(-1,'0');
    while(!q.empty())
    {
        node p=q.top();
        q.pop();
        if(p.hash==0)
        {
            long long ww=0;
            top=0;
            while(mp[ww].w!=-1)
            {
                ans[top++]=mp[ww].c;
                ww=mp[ww].w;
            }
            for(int i=top-1;i>=0;i--)
                printf("%c",ans[i]);
            printf("\n");
            return;
        }
        for(int i=0;i<4;i++)
        {
            node pp=p;
            pp.x+=tur[i][0];
            pp.y+=tur[i][1];
            pp.g++;
            if(pp.x<0||pp.y<0||pp.x>2||pp.y>2)continue;
            int tmp=pp.a[pp.x][pp.y];
            pp.a[pp.x][pp.y]=pp.a[p.x][p.y];
            pp.a[p.x][p.y]=tmp;
            pp.caclu();
            if(mp[pp.hash].w!=-2)continue;
            mp[pp.hash]=nd(p.hash,ch[i]);
            q.push(pp);
        }
    }
    printf("unsolvable\n");
}
bool check(node s)
{
    int aa[10],top=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(s.a[i][j]!=9)aa[top++]=s.a[i][j];
        }
    int cnt=0;
    for(int i=0;i<top;i++)
        for(int j=0;j<i;j++)
            if(aa[i]<aa[j])cnt++;
    return cnt&1;
}
int main()
{
    char aa[5];
    while(scanf("%s",aa)==1)
    {
        node s;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(!(i==0&&j==0))scanf("%s",aa);
                if(aa[0]=='x')
                {
                    s.a[i][j]=9;
                    s.x=i;
                    s.y=j;
                }
                else s.a[i][j]=(aa[0]-'0');
            }
        s.g=0;
        s.caclu();
        if(s.hash==0)printf("lr\n");
        else if(check(s))printf("unsolvable\n");
        else Astar(s);
    }
}

