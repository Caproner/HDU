#include<stdio.h>
int main()
{
    //freopen("data.in","r",stdin);
    int n,i;
    long long a[51];
    a[0]=0;
    a[1]=1;
    for(i=2;i<51;i++)a[i]=a[i-1]+a[i-2];
    while(scanf("%d",&n)==1&&n+1)
    {
        printf("%lld\n",a[n]);
    }
}
