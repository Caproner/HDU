#include<stdio.h>
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,i;
        double b[100];
        scanf("%d",&a);
        for(i=0;i<a;i++)scanf("%lf",&b[i]);
        double max=b[0];
        for(i=1;i<a;i++)if(max<b[i])max=b[i];
        printf("%.2lf\n",max);
    }
}
