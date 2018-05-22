#include<cmath>
#include<cstdio>
#include<cstring>
#define eps 1e-8
#define zero(x) (((x)>0?(x):(-x))<eps)//以1e-8为精度判断是否为零
#define MAXN 1000//数组最大值，可修改
#define offset 10000
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))//以1e-8为精度返回x的正负，正则返回1，负则返回2,0则返回0 


//计算几何通用结构体 
struct point
{
    double x,y;
}; 
struct line
{
    point a,b;
};

//工具函数，计算（P1-P0）x(P2-P0) 
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
} 

double PolygonArea(int n,point *p)
{
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=xmult(p[i],p[i+1],p[0]);
    return area/2.0;
}

//测试用main函数 

point p[1000005];

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        double ans=PolygonArea(n,p);
        if(ans<0)ans=-ans;
        printf("%.1lf\n",ans);
    }
}
