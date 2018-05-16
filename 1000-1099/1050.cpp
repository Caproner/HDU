#include<cstdio>
#include<algorithm>
using namespace std;
struct way
{
    int s,t;
    bool isuse;
};
bool comp(way a,way b)
{
    return a.s<b.s||(a.s==b.s&&a.t<b.t);
}
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            int n;
            scanf("%d",&n);
            way a[205];
            for(int i=0;i<n;i++)
            {
                scanf("%d%d",&a[i].s,&a[i].t);
                a[i].s=(a[i].s+1)/2;
                a[i].t=(a[i].t+1)/2;
                if(a[i].s>a[i].t)swap(a[i].s,a[i].t);
                a[i].isuse=false;
            }
            sort(a,a+n,comp);
            int ans=0;
            for(int i=0;i<n;i++)
            {
                if(a[i].isuse)continue;
                a[i].isuse=true;
                int p=a[i].t;
                for(int j=i+1;j<n;j++)
                {
                    if(a[j].isuse)continue;
                    if(a[j].s>p)
                    {
                        p=a[j].t;
                        a[j].isuse=true;
                    }
                }
                ans+=10;
            }
            printf("%d\n",ans);
        }
    }
}