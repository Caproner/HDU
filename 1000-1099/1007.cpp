#include<cmath>
#include<cstdlib>
#include<algorithm>
#define eps 1e-8
#define zero(x) (((x)>0?(x):(-x))<eps)//以1e-8为精度判断是否为零
#define MAXN 100005//数组最大值，可修改
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
//以1e-8为精度返回x的正负，正则返回1，负则返回2,0则返回0 
#define INF 10000000
//计算几何通用结构体 
using namespace std;
struct Point
{
    double x,y;
}; 
struct Line
{
    Point a,b;
    Line(){}
    Line(Point aa,Point bb)
    {
        a=aa;
        b=bb;
    }
};
//按点的x值进行排序 
bool Comp_x(Point a,Point b)
{
    return a.x<b.x;
}
//按点的y值进行排序 
bool Comp_y(Point a,Point b)
{
    return a.y<b.y;
}
double Distance(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Point qp[MAXN];//合并时用的临时数组 
int qpp;//临时数组的长度值 
//分治法解决最近点对问题 
double Divide_solve(int s,int t,Point *p)
{
    if(t-s==1)return INF;
    if(t-s==2)return Distance(p[s],p[s+1]);
    if(t-s==3)
    {
        double t1=Distance(p[s],p[s+1]);
        double t2=Distance(p[s],p[s+2]);
        double t3=Distance(p[s+1],p[s+2]);
        if(t1>t2)t1=t2;
        if(t1>t3)t1=t3;
        return t1;
    }
    double midx=p[(s+t)/2].x;
    double ans1=Divide_solve(s,(s+t)/2,p);
    double ans2=Divide_solve((s+t)/2,t,p);
    if(ans1>ans2)ans1=ans2;
    double f=ans1/2;
    double ans=ans1;
    qpp=0; 
    for(int i=(s+t)/2-1;i>=s;i--)
    {
        if(midx-p[i].x>f)break;
        qp[qpp++]=p[i];
    }
    for(int i=(s+t)/2;i<t;i++)
    {
        if(p[i].x-midx>f)break;
        qp[qpp++]=p[i];
    }
    sort(qp,qp+qpp,Comp_y);
    for(int i=0;i<qpp;i++)
    {
        for(int j=i+1;j<qpp;j++)
        {
            if(qp[j].y-qp[i].y>ans)break;
            double pans=Distance(qp[i],qp[j]);
            if(pans<ans)ans=pans;
        }
    }
    return ans;
    
}
//最近点对问题的接口函数 
//参数表：点的个数n，包含所有点的数组p 
//返回值：最近点对距离
//时间复杂度为O(nlogn) 
double Solve(int n,Point *p)
{
    sort(p,p+n,Comp_x);
    return Divide_solve(0,n,p);
}
/////////////////////////////////////////////////////
#include<cstdio>
Point P[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
        double ans=Solve(n,P);
        printf("%.2lf\n",ans/2);
    }
}
