#include<stdio.h>
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    while(scanf("%d",&n)==1&&(n+1))
    {
        long long a=1,b=0;
        while(n--)
        {
            long long aa=0,bb=0;
            aa+=(a*3+b*2);
            bb+=(a+b);;
            a=aa;
            b=bb;
        }
        printf("%lld, %lld\n",a,b);
    }
}
