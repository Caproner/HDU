#include<cstdio>
#include<cstring>
long long ans[121],b[121];
int main()
{
    for(int i=0;i<121;i++)ans[i]=1;
    for(int i=2;i<121;i++)
    {
        memcpy(b,ans,sizeof(b));
        for(int j=i;j<121;j+=i)
        {
            for(int k=0;k+j<121;k++)ans[k+j]+=b[k];
        }
    }
    int n;
    while(scanf("%d",&n)==1)printf("%lld\n",ans[n]);
}
