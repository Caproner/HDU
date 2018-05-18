#include<bits/stdc++.h>
using namespace std;
bool dp[10005];
vector<int> v;
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3&&(a||b||c))
    {
        v.clear();
        for(int i=1;i<=a;i<<=1)
        {
            v.push_back(i);
            a-=i;
        }
        if(a)v.push_back(a);
        for(int i=1;i<=b;i<<=1)
        {
            v.push_back(i*2);
            b-=i;
        }
        if(b)v.push_back(b*2);
        for(int i=1;i<=c;i<<=1)
        {
            v.push_back(i*5);
            c-=i;
        }
        if(c)v.push_back(c*5);
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<v.size();i++)
            for(int j=10000;j>=0;j--)
                if(j-v[i]>=0)
                    dp[j]|=dp[j-v[i]];
        int ans=0;
        while(dp[ans])ans++;
        printf("%d\n",ans);
    }
}
