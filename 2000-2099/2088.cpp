#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("data.in","r",stdin);
    int n,h[50],k=1;
    while(scanf("%d",&n)==1&&n)
    {
        if(k)k=0;
        else printf("\n");
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            sum+=h[i];
        }
        sum/=n;
        int s=0;
        for(int i=0;i<n;i++)
        {
            h[i]=sum-h[i];
            if(h[i]<0)h[i]=-h[i];
            s+=h[i];
        }
        s/=2;
        printf("%d\n",s);
    }
}
