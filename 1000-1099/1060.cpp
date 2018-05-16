#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        double ans=log10((double)n);
//        printf("%lf\n",ans);
        ans*=n;
//        printf("%lf\n",ans);
        ans=fmod(ans,1);
//        printf("%lf\n",ans);
        ans=pow(10.0,ans);
//        printf("%lf\n",ans);
        printf("%d\n",(int)ans);
    }
}
