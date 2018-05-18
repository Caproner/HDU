#include<bits/stdc++.h>
using namespace std;
int mp[105][105];
int dp(int *a,int n)
{
    int dp[105];
    dp[0]=a[0];
    int ret=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(a[i],dp[i-1]+a[i]);
        ret=max(dp[i],ret);
    }
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mp[i][j]);
        int s[105];
        int ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                s[j]=mp[i][j];
            int pans=dp(s,n);
            if(i==0)ans=pans;
            for(int j=i+1;j<n;j++)
            {
                for(int k=0;k<n;k++)
                    s[k]+=mp[j][k];
                pans=max(pans,dp(s,n));
            }
            ans=max(ans,pans);
        }
        printf("%d\n",ans);
    }
}
