#include<stdio.h>
int main()
{
    long long a[10001];
    int i,n,m;
    a[1]=2;
    for(i=2;i<10001;i++)a[i]=a[i-1]+(i*4-3);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%lld\n",a[m]);
    }
}
