#include<cstdio>
using namespace std;
int main()
{
    long long a,b;
    int n;
    scanf("%d",&n);
    while(n--&&scanf("%lld %lld",&a,&b)==2)printf("%lld\n",a+b);
}
