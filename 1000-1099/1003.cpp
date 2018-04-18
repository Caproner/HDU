#include<cstdio>
using namespace std;
int main()
{
    int n,k=0;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        if(k)printf("\n");
        int m,a[100000];
        scanf("%d",&m);
        for(int i=0;i<m;i++)scanf("%d",&a[i]);
        int b[100000],ans,l=0,r=0,ll=0,rr=0;
        b[0]=a[0];
        ans=b[0];
        for(int i=1;i<m;i++)
        {
            if(a[i]<=b[i-1]+a[i])
            {
                b[i]=b[i-1]+a[i];
                rr++;
            }
            else
            {
                b[i]=a[i];
                ll=i;
                rr=i;
            }
            if(ans<b[i])
            {
                ans=b[i];
                l=ll;
                r=rr;
            }
        }
        printf("Case %d:\n%d %d %d\n",j+1,ans,l+1,r+1);
        k=1;
    }
}
