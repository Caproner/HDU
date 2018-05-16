#include<bits/stdc++.h>
using namespace std;
struct cube
{
    int x,y,z;
    cube(){}
    cube(int xx,int yy,int zz):x(xx),y(yy),z(zz){}
    bool operator <(const cube &a)const
    {
        if(x!=a.x)return x<a.x;
        if(y!=a.y)return y<a.y;
        return z<a.z;
    }
};
cube a[205];
long long dp[205];
int main()
{
    int n,cas=1;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[6*i]=cube(x,y,z);
            a[6*i+1]=cube(x,z,y);
            a[6*i+2]=cube(y,x,z);
            a[6*i+3]=cube(y,z,x);
            a[6*i+4]=cube(z,x,y);
            a[6*i+5]=cube(z,y,x);
        }
        sort(a,a+6*n);
        dp[0]=a[0].z;
        long long ans=dp[0];
        for(int i=1;i<6*n;i++)
        {
            dp[i]=a[i].z;
            for(int j=0;j<i;j++)
                if(a[j].x<a[i].x&&a[j].y<a[i].y)
                    dp[i]=max(dp[i],a[i].z+dp[j]);
            if(ans<dp[i])ans=dp[i];
        }
        printf("Case %d: maximum height = %lld\n",cas++,ans);
    }
}
