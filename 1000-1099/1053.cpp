#include<bits/stdc++.h>
using namespace std;
struct Haffman
{
    char ch;
    int l,r,w;
};
struct node
{
    int p,w;
    node(){}
    node(int pp,int ww):p(pp),w(ww){}
    bool operator <(const node &a)const
    {
        return a.w<w;
    }
};
Haffman a[10005];
int top;
char s[100005];
void init()
{
    top=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int j;
        for(j=0;j<top;j++)
            if(a[j].ch==s[i])
            {
                a[j].w++;
                break;
            }
        if(j==top)
        {
            a[top].l=-1;
            a[top].r=-1;
            a[top].ch=s[i];
            a[top].w=1;
            top++;
        }
//        printf("**********\n");
//        for(j=0;j<top;j++)
//            printf("%c: %d\n",a[j].ch,a[j].w);
    }
}
int dfs(int p,int d)
{
    if(a[p].ch!=0)
        return a[p].w*d;
    return dfs(a[p].l,d+1)+dfs(a[p].r,d+1);
}
int solve()
{
    init();
    priority_queue<node> q;
    for(int i=0;i<top;i++)
    {
//        printf("%c: %d\n",a[i].ch,a[i].w);
        q.push(node(i,a[i].w));
    }
    int root;
    while(!q.empty())
    {
        node p1=q.top();
        q.pop();
        if(q.empty())
        {
            root=p1.p;
            break;
        }
        node p2=q.top();
        q.pop();
        a[top].l=p1.p;
        a[top].r=p2.p;
        a[top].w=p1.w+p2.w;
        a[top].ch=0;
        q.push(node(top,a[top].w));
        top++;
    }
    int ret=dfs(root,0);
    if(ret==0)return a[root].w;
    return ret;
}
int main()
{
    while(scanf("%s",s)==1&&strcmp(s,"END"))
    {
        int len=strlen(s)*8,ans=solve();
        printf("%d %d %.1lf\n",len,ans,(double)len/(double)ans);
    }
}