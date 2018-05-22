#include<stdio.h>
int a[100][2];
int maxa(int n)
{
    int i,max=a[0][1];
    for(i=0;i<n;i++)if(a[i][1]>max)max=a[i][1];
    return max;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i,p=0,j,b[100000];
        if(n==0)break;
        for(i=0;i<n;i++)scanf("%d %d",&a[i][0],&a[i][1]);
        p=maxa(n);
        b[0]=0;
        for(i=1;i<=p;i++)
        {
            int max=0;
            for(j=0;j<n;j++)
            {
                if(a[j][1]==i)
                {
                    if(max<b[a[j][0]]+1)max=b[a[j][0]]+1;
                }
            }
            if(max<b[i-1])max=b[i-1];
            b[i]=max;
        }
        printf("%d\n",b[p]);
    }
    return 0;
}
