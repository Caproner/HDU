#include <bits/stdc++.h>

using namespace std;

#define sfi(a) scanf("%d",&a)
#define sfd(a) scanf("%lf",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)

#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define dwn(i,b,a) for(int i=int(b-1);i>=int(a);--i)

#define mem(a,p) memset(a,p,sizeof(a))

typedef long long LL;
typedef unsigned UINT;
typedef unsigned long long ULL;

LL dp[10][3];
LL pw[10];

LL dfs(int pos,int pre)
{
    if(dp[pos][pre]!=-1)return dp[pos][pre];
    if(pos==0)return dp[pos][pre]=1;
    
    dp[pos][pre]=0;
    rep(i,0,10)
    {
        if(i==4)continue;
        if(pre&&i==2)continue;
        if(i==6)dp[pos][pre]+=dfs(pos-1,1);
        else dp[pos][pre]+=dfs(pos-1,0);
    }
    
    return dp[pos][pre];
}

LL Solve(LL P)
{
    LL ans=0;
    int pre=0;
    bool flag=true;
    dwn(i,10,0)
    {
        int p=(P/pw[i])%10;
        rep(k,0,p)
        {
            if(k==4)continue;
            if(k==2&&pre)continue;
            if(k==6)ans+=dfs(i,1);
            else ans+=dfs(i,0);
        }
        if(p==4||(p==2&&pre))
        {
            flag=false;
            break;
        }
        if(p==6)pre=1;
        else pre=0;
    }
    if(flag)ans++;
    return ans;
}

int main()
{
    pw[0]=1;
    rep(i,1,10)pw[i]=pw[i-1]*10;
    mem(dp,-1);
    LL l,r;
    while(scanf("%lld%lld",&l,&r)==2&&(l||r))
    {
        printf("%lld\n",Solve(r)-Solve(l-1));
    }
}
