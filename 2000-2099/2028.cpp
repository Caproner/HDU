#include<stdio.h>
#include<string.h>
int main()
{
    int n,a[100000],i,j,b;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        b=0;
        for(i=1;b==0;i++)
        {
            b=1;
            for(j=0;j<n;j++)if(i%a[j]!=0)
            {
                b=0;
                break;
            }
        }
        i--;
        printf("%d\n",i);
    }
    return 0;
}
