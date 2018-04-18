#include<stdio.h>
int main()
{
    long a,b,n,f[100];
    while(scanf("%ld%ld%ld",&a,&b,&n) && a!=0)
    {
        f[1]=f[2]=1;
        for(int i=3;i<=48;i++)
            f[i]=(a*f[i-1]+b*f[i-2])%7;
        printf("%ld\n",f[(n>48)?n%48:n]);
    }
    return 0;
}
