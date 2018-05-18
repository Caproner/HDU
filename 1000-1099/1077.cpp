#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double xx,double yy):x(xx),y(yy){}
    double operator -(point a)
    {
        return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
    }
};
point a[305];
int check(point p,int n)
{
    int ret=0;
    for(int i=0;i<n;i++)
        if(a[i]-p<1.0001)ret++;
    return ret;
}
point fix(point p,point v,double d)
{
    double pp=sqrt(v.x*v.x+v.y*v.y);
    v.x/=pp;
    v.y/=pp;
    v.x*=d;
    v.y*=d;
    return point(p.x+v.x,p.y+v.y);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c=check(a[i],n);
            if(ans<c)ans=c;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(a[i]-a[j]==0||a[i]-a[j]>2.0002)continue;
                point p=point((a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2);
                int c1=check(fix(p,point(a[i].y-a[j].y,a[j].x-a[i].x),sqrt(1.0000999*1.0000999-(a[i]-p)*(a[i]-p))),n);
                int c2=check(fix(p,point(a[j].y-a[i].y,a[i].x-a[j].x),sqrt(1.0000999*1.0000999-(a[i]-p)*(a[i]-p))),n);
                if(ans<c1)ans=c1;
                if(ans<c2)ans=c2;
            }
        printf("%d\n",ans);
    }
