#include<stdio.h>
int main()
{
    int n,i;
    long long c[51];
    c[1]=3;
    c[2]=8;
    c[3]=22;
    for(i=4;i<51;i++)c[i]=c[i-1]*3-c[i-3]*2;
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",c[n]);
    }
}
