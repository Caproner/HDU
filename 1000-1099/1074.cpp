#include<bits/stdc++.h>
using namespace std;
struct node
{
    char s[105];
    int a,b;
};
int dp[20][40005],n;
int prt[20][40005][2];
node a[20];
int dfs(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    int w=0;
    for(int ii=0,jj=1;ii<n;ii++,jj<<=1)
        if(j&jj)w+=a[ii].b;
    w-=a[i].a;
    if(w<0)w=0;
//    printf("%d %d %d\n",i,j,w);
    for(int ii=0,jj=1;ii<n;ii++,jj<<=1)
    {
        if(ii==i)continue;
        if(jj&j)
        {
            int pans=dfs(ii,j^(1<<i))+w;
            if(dp[i][j]==-1||dp[i][j]>pans)
            {
                dp[i][j]=pans;
                prt[i][j][0]=ii;
                prt[i][j][1]=j^(1<<i);
            }
        }
    }
    if(dp[i][j]==-1)
    {
        dp[i][j]=w;
        prt[i][j][0]=i;
    }
    return dp[i][j];
}
bool comp(node aa,node bb)
{
    return strcmp(aa.s,bb.s)>0;
}
char stk[105][105];
int top=0;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i].s);
            scanf("%d%d",&a[i].a,&a[i].b);
        }
        sort(a,a+n,comp);
        int k=1;
        for(int i=1;i<n;i++)
            k=(k<<1)+1;
        memset(dp,-1,sizeof(dp));
        memset(prt,-1,sizeof(prt));
        int ans=dfs(0,k);
        int p=0;
        for(int i=1;i<n;i++)
        {
            if(ans>dfs(i,k))
            {
                ans=dp[i][k];
                p=i;
            }
        }
        printf("%d\n",ans);
        top=0;
        while(prt[p][k][0]!=p)
        {
//            printf("*%d %d %s\n",p,k,a[p].s);
            strcpy(stk[top],a[p].s);
            top++;
            int pp=p;
            p=prt[p][k][0];
            k=prt[pp][k][1];
//            printf("*%d %d %s\n",p,k,a[p].s);
        }
        strcpy(stk[top],a[p].s);
        for(int i=top;i>=0;i--)
            printf("%s\n",stk[i]);
//        for(int i=0;i<n;i++)
//            for(int j=0;j<(1<<n);j++)
//                printf("dp[%d][%d]=\t%d\tprt[%d][%d]=\t%d\t%d\n",i,j,dp[i][j],i,j,prt[i][j][0],prt[i][j][1]);
//        for(int i=0;i<n;i++)
//            printf("%s\n",a[i].s);
    }
}
