#include<stdio.h>
#include<string.h>
int main()
{
    int n,a[6];
    scanf("%d",&n);
    while(n--)
    {
        int i;
        for(i=0;i<6;i++)scanf("%d",&a[i]);
        a[2]+=a[5];
        if(a[2]>=60)
        {
            a[2]-=60;
            a[5]=1;
        }
        else a[5]=0;
        a[1]+=(a[4]+a[5]);
        if(a[1]>=60)
        {
            a[1]-=60;
            a[4]=1;
        }
        else a[4]=0;
        a[0]+=(a[3]+a[4]);
        printf("%d %d %d\n",a[0],a[1],a[2]);
    }
    return 0;
}
