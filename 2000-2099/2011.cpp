#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,j,i;
    double ans;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&n);
        ans=1;
        for(j=1;j<n;j++)
        {
            if(j%2==1)ans-=1/(double)(j+1);
            else ans+=1/(double)(j+1);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
