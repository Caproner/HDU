#include<stdio.h>
int main()
{
    long long a;
    int m;
    while(scanf("%d",&m)==1)
    {
        int i;
        a=2;
        for(i=1;i<m;i++)a=3*a+2;
        printf("%lld\n",a);
    }
}
