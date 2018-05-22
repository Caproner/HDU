#include<stdio.h>
#include<string.h>
int main()
{
    int n,a[100],i,p,j;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            a[0]=1;
            p=i;
            for(j=1;j-1<i;j++,p--)a[j]=a[j-1]*p/j;
            for(j=0;j<i+1;j++)
            {
                if(j==0)printf("%d",a[j]);
                else printf(" %d",a[j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
