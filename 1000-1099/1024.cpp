#include<bits/stdc++.h>
using namespace std;
int dp[2][1000005];
int a[1000005];
int sum[1000005];
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp[1],0,sizeof(int)*(n+1));
        int cur=0;
        for(int i=1;i<=m;i++)
        {
            dp[cur][i]=sum[i];
            for(int j=i+1;j<=n;j++)
                dp[cur][j]=max(dp[cur][j-1],dp[cur^1][j-1])+a[j];
            for(int j=i+1;j<=n;j++)
                dp[cur][j]=max(dp[cur][j],dp[cur][j-1]);
            cur^=1;
        }
        printf("%d\n",dp[cur^1][n]);
    }
}
