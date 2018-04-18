#include <bits/stdc++.h>

using namespace std;

#define sfi(a) scanf("%d",&a)
#define sfd(a) scanf("%lf",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)

#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define dwn(i,b,a) for(int i=int(b-1);i>=int(a);--i)

#define mem(a,p) memset(a,p,sizeof(a))

typedef long long LL;
typedef unsigned UINT;
typedef unsigned long long ULL;

int main()
{
    LL n;
    while(sfl(n)==1)
    {
        LL ans=n;
        ans+=1;
        ans*=n;
        ans/=2;
        printf("%lld\n\n",ans);
    }
}
