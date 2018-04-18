#include<cstdio>
#include<algorithm>
using namespace std;
struct room
{
    double j,f;
    double p;
};
bool comp(room a,room b)
{
    return a.p>b.p;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2&&((m+1)||(n+1)))
    {
        room a[1005];
        double ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i].j,&a[i].f);
            a[i].p=a[i].j/a[i].f;
        }
        sort(a,a+n,comp);
        double ap=0;
        for(int i=0;i<n&&ap<m;i++)
        {
            //printf("%lf %lf %lf %lf\n",a[i].j,a[i].f,a[i].p,ans);
            if(ap+a[i].f<=m)
            {
                ap+=a[i].f;
                ans+=a[i].j;
            }
            else
            {
                ap=m-ap;
                ans+=(a[i].j*ap/a[i].f);
                break;
            }
        }
        printf("%.3lf\n",ans);
    }
}
