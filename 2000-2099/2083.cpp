#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("data.in","r",stdin);    
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,ans;
        scanf("%d",&m);
        int a[500];
        for(int i=0;i<m;i++)scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        {
            int an=0;
            for(int j=0;j<m;j++)an+=abs(a[i]-a[j]);
            if(i==0)ans=an;
            else if(an<ans)ans=an;
        }
        printf("%d\n",ans);
    }
}
