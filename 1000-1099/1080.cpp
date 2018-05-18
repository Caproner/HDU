#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
char a[1005],b[1005];
int change(char aa,char bb)
{
    if(aa=='A')
    {
        if(bb=='A')return 5;
        if(bb=='C')return -1;
        if(bb=='G')return -2;
        if(bb=='T')return -1;
        if(bb=='-')return -3;
    }
    if(aa=='C')
    {
        if(bb=='A')return -1;
        if(bb=='C')return 5;
        if(bb=='G')return -3;
        if(bb=='T')return -2;
        if(bb=='-')return -4;
    }
    if(aa=='G')
    {
        if(bb=='A')return -2;
        if(bb=='C')return -3;
        if(bb=='G')return 5;
        if(bb=='T')return -2;
        if(bb=='-')return -2;
    }
    if(aa=='T')
    {
        if(bb=='A')return -1;
        if(bb=='C')return -2;
        if(bb=='G')return -2;
        if(bb=='T')return 5;
        if(bb=='-')return -1;
    }
    if(aa=='-')
    {
        if(bb=='A')return -3;
        if(bb=='C')return -4;
        if(bb=='G')return -2;
        if(bb=='T')return -1;
        if(bb=='-')return 0;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%s",&n,a);
        scanf("%d%s",&m,b);
        dp[0][0]=0;
        for(int i=0;i<n;i++)
        {
            dp[i+1][0]=dp[i][0]+change(a[i],'-');
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i+1]=dp[0][i]+change(b[i],'-');
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                dp[i+1][j+1]=max(dp[i][j+1]+change(a[i],'-'),dp[i+1][j]+change(b[j],'-'));
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+change(a[i],b[j]));
            }
        printf("%d\n",dp[n][m]);
    }
}
