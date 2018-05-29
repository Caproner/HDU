#include<stdio.h>
int main()
{
    //freopen("data.in","r",stdin);
    int m;
    scanf("%d",&m);
    long long ans[20];
    ans[0]=0;
    for(int i=1;i<20;i++)ans[i]=ans[i-1]*3+2;
    while(m--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n-1]+2);
    }
}
