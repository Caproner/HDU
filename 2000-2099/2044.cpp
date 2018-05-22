#include<stdio.h>
int main()
{
    int n,a,b,i;
    long long c[50];
    c[0]=0;
    c[1]=1;
    c[2]=2;
    for(i=3;i<50;i++)c[i]=c[i-1]+c[i-2];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        a=b-a;
        printf("%lld\n",c[a]);
    }
}
