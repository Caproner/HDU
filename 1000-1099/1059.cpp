#include<bits/stdc++.h>
using namespace std;
bool dp[120005];
vector<int> v;
int main()
{
    int a[7];
    int cas=1;
    while(true)
    {
        int s=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&a[i]);
            s+=(a[i]*i);
        }
        if(!s)break;
        printf("Collection #%d:\n",cas++);
        if(s&1)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        s/=2;
        memset(dp,0,sizeof(dp));
        v.clear();
        for(int i=1;i<=6;i++)
        {
            for(int k=1;a[i]>=k;k<<=1)
            {
                v.push_back(i*k);
                a[i]-=k;
            }
            if(a[i]!=0)v.push_back(a[i]*i);
        }
        dp[0]=true;
        for(int i=0;i<v.size();i++)
        {
        //    printf("%d\n",v[i]);
            for(int j=s;j>=0;j--)
                if(j-v[i]>=0)dp[j]=dp[j]|dp[j-v[i]];
        }
        if(dp[s])printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
}
