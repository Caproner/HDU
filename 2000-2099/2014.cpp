#include<stdio.h>
#include<math.h>
int main()
{
    int n,a[100],i,max,min;
    double ans;
    while(scanf("%d",&n)==1)
    {
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i==0)
            {
                max=0;
                min=0;
            }
            else if(a[i]>a[max])max=i;
            else if(a[i]<a[min])min=i;
            else;
        }
        for(i=0;i<n;i++)
        {
            if(i!=max&&i!=min)ans+=a[i];
        }
        ans=ans/(n-2);
        printf("%.2lf\n",ans);
    }
    return 0;
}
