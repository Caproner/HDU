#include<stdio.h>
int main()
{
    int n,m,a[40],i;
    a[0]=0;
    a[1]=1;
    a[2]=2;
    for(i=3;i<40;i++)a[i]=a[i-1]+a[i-2];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%d\n",a[m-1]);
    }
}
