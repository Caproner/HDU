#include<cstdio>
using namespace std;
int main()
{
    int n,m;
    scanf("%d",&m);
    while(m--&&scanf("%d",&n)==1&&n)
    {
        long long a,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a);
            ans+=a;
        }
        printf("%lld\n",ans);
    }
}
