#include<stdio.h>
int main()
{
    int n,i;
    long long c[51];
    c[1]=1;
    c[2]=2;
    c[3]=3;
    for(i=4;i<51;i++)c[i]=c[i-2]+c[i-1];
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",c[n]);
    }
}
