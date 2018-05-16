#include<bits/stdc++.h>
using namespace std;
struct node
{
    int i;
    int a,b,c;
    node(){}
    node(int ii,int aa,int bb,int cc):i(ii),a(aa),b(bb),c(cc){}
    bool operator <(const node &aa)const
    {
        if(b*aa.c!=aa.b*c)return b*aa.c<aa.b*c;
        if(a!=aa.a)return a<aa.a;
        return i<aa.i;
    }
};
node a[1005];
int prt[1005];
int pr[1005];
int n,r;
bool vis[1005];
int solve()
{
    memset(vis,0,sizeof(vis));
    priority_queue<node> q;
    for(int i=1;i<=n;i++)
        q.push(a[i]);
    int ans;
    while(!q.empty())
    {
        node p=q.top();
        q.pop();
//        printf("%d %d %d %d\n",p.i,p.a,p.b,p.c);
        if(p.i==r)continue;
        if(!(p.a==a[p.i].a&&p.b==a[p.i].b&&p.c==a[p.i].c))continue;
        if(vis[p.i])continue;
        vis[p.i]=true;
        int pp=prt[pr[p.i]];
        while(prt[pp]!=pp)pp=prt[pp];
        prt[p.i]=pp;
//        for(int i=1;i<=n;i++)
//            printf("%d ",prt[i]);
//        printf("\n");
        p.i=pp;
        p.a=a[pp].a+p.a+p.b*a[pp].c;
        p.b+=a[pp].b;
        p.c+=a[pp].c;
        a[p.i].a=p.a;
        a[p.i].b=p.b;
        a[p.i].c=p.c;
        q.push(p);
    }
    return a[r].a;
}
int main()
{
    while(scanf("%d%d",&n,&r)==2&&(n||r))
    {
        for(int i=1;i<=n;i++)
        {
            int p;
            scanf("%d",&p);
            a[i].i=i;
            a[i].a=p;
            a[i].b=p;
            a[i].c=1;
            prt[i]=i;
        }
        for(int i=1;i<n;i++)
        {
            int uu,vv;
            scanf("%d%d",&uu,&vv);
            pr[vv]=uu;
        }
        printf("%d\n",solve());
    }
}