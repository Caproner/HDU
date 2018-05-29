#include<stdio.h>
long long a[251];
int b[5]={50,25,10,5,1};
long long d(int i,int j,int h)
{
    long long ans=0;
    if(h==100)return 0;
    if(i<2)return 1;
    if(i<b[j])
    {
        //printf("out,pro:%d\n",b[j]);
        return d(i,j+1,h);
    }
    else 
    {
        for(int k=j;k<5;k++)ans+=d(i-b[k],k,h+1);
        //printf("ans=%lld\n",ans);
        return ans;
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    int i,n;
    a[1]=1;
    a[0]=1;
    for(i=2;i<251;i++)
    {
        a[i]=d(i,0,0);
        //printf("%d:%lld\n",i,a[i]);
    }
    while(scanf("%d",&n)==1)
        printf("%lld\n",a[n]);
}
