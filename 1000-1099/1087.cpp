#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1005];
ll a[1005];
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        dp[0]=a[0];
        ll ans=dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=a[i];
            for(int j=0;j<i;j++)
                if(a[j]<a[i])
                    dp[i]=max(dp[i],a[i]+dp[j]);
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
}
