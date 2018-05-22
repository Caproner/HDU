#include<stdio.h>
int ca(int n,int m)
{
    int i;
    long long ans=1;
    for(i=n;i>n-m;i--)ans*=i;
    for(i=1;i<=m;i++)ans/=i;
    return (int)ans;
}
int main()
{
    int c,n,m,i,j;
    long long a[21];
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d %d",&n,&m);
        a[0]=1;
        a[1]=0;
        for(i=2;i<=m;i++)a[i]=(i-1)*(a[i-1]+a[i-2]);
        a[m]=a[m]*ca(n,m);
        printf("%lld\n",a[m]);
    }
}
