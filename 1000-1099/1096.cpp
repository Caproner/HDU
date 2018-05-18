#include<cstdio>
using namespace std;
int main()
{
    int n,k=0,m;
    scanf("%d",&m);
    while(m--&&scanf("%d",&n)==1)
    {
        if(k)printf("\n");
        long long a,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a);
            ans+=a;
        }
        printf("%lld\n",ans);
        k=1;
    }
}
