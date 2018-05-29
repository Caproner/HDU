#include<stdio.h>
int a[40];
void qs(int l,int r)
{
    int i=l,j=r,p=i,t;
    while(i<j)
    {
        for(;a[j]>=a[p]&&j>p;j--);
        t=a[p];
        a[p]=a[j];
        a[j]=t;
        p=j;
        for(;a[i]<=a[p]&&i<p;i++);
        t=a[p];
        a[p]=a[i];
        a[i]=t;
        p=i;
    }
    if(l<r)
    {
        qs(l,p-1);
        qs(p+1,r);
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        qs(0,n-1);
        int ans=100-a[0];
        ans=ans*ans;
        printf("%d\n",ans);
    }
}
