#include<stdio.h>
#include<math.h>
int main()
{
    long long m,i,ans;
    while(scanf("%lld",&m)==1)
    {
        ans=1;
    for(i=1;i<m;i++)
    {
        ans++;
        ans=ans*2;
    }
    printf("%lld\n",ans);
    }
    return 0;
}
