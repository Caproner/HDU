#include<stdio.h>
int main()
{
    int n,i;
    long long c[51];
    c[1]=3;
    c[2]=6;
    c[3]=6;
    for(i=4;i<51;i++)c[i]=c[i-2]*2+c[i-1];
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",c[n]);
    }
}
