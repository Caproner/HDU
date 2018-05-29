#include<cstdio>
int main()
{
    unsigned long long k[36];
    k[1]=1;
    for(int i=2;i<=35;i++)
    {
        unsigned long long p=0;
        for(int j=0;j<i;j++)p+=(k[j]*k[i-j-1]);
        k[i]=p;
    }
    int n,p=1;
    while(scanf("%d",&n)==1&&n!=-1)
    {
        printf("%d %d %llu\n",p,n,k[n]*2);
        p++;
    }
    return 0;
}
