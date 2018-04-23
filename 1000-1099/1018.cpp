#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double n;
        scanf("%lf",&n);
        double ans=log10(sqrt(2*acos(-1)*n))+n*log10(n/exp(1));
        long long p=ans;
        printf("%lld\n",p+1);
    }
}
