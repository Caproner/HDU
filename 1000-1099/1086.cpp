#include<cmath>
#include<cstdlib>
#define eps 1e-8
#define zero(x) (((x)>0?(x):(-x))<eps)//以1e-8为精度判断是否为零
#define MAXN 1000//数组最大值，可修改
//#define offset 10000
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))//以1e-8为精度返回x的正负，正则返回1，负则返回2,0则返回0 


//计算几何通用结构体 
struct point
{
    double x,y;
}; 
struct line
{
    point a,b;
    line(){};
    line(point aa,point bb)
    {
        a=aa;
        b=bb;
    }
};

//工具函数，计算（P1-P0）x(P2-P0) 
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
} 

//工具函数，计算（P1-P0）·（P2-P0）
double dmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
} 

int dots_inline(point p1,point p2,point p3)
{
    return zero(xmult(p1,p2,p3));
}
double distance(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int same_side(point p1,point p2,line l)
{
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
int dot_online_in(point p,line l)
{
    if(!zero(xmult(p,l.a,l.b)))return false;
    if((l.a.x-p.x)*(l.b.x-p.x)>eps)return false;
    if((l.a.y-p.y)*(l.b.y-p.y)>eps)return false;
    return true;
}
int intersect_in(line u,line v)
{
    bool check1=!dots_inline(u.a,u.b,v.a);
    bool check2=!dots_inline(u.a,u.b,v.b);
    bool check3=!same_side(u.a,u.b,v);
    bool check4=!same_side(v.a,v.b,u);
    bool check5=dot_online_in(u.a,v);
    bool check6=dot_online_in(u.b,v);
    bool check7=dot_online_in(v.a,u);
    bool check8=dot_online_in(v.b,u);
    if(check1||check2)
        return check3&&check4;
    return check5||check6||check7||check8;
}
double disptoseg(point p,line l)
{
    point t=p;
    t.x+=l.a.y-l.b.y,t.y+=l.b.x-l.a.x;
    if(xmult(l.a,t,p)*xmult(l.b,t,p)>eps)
        return distance(p,l.a)<distance(p,l.b)?distance(p,l.a):distance(p,l.b);
    return fabs(xmult(p,l.a,l.b))/distance(l.a,l.b);
}


//参数表：计算线段l1，l2 
//返回值：两线段的最短距离 
//需要以下六个函数：
//需要计算两点间距离的函数：distance() 
//判断三点共线：dots_inline()
//判断两个点是否在线的同侧：same_side()
//判断点是否在线上：dot_online_in() 
//判断两线段是否相交（包括端点和重合边）的函数：intersect_in()
//计算点到线段的最短距离的函数：disptoseg() 
double dissegtoseg(line l1,line l2)
{
    if(intersect_in(l1,l2))return 0;
    double ans=disptoseg(l1.a,l2);
    if(ans>disptoseg(l1.b,l2))ans=disptoseg(l1.b,l2);
    if(ans>disptoseg(l2.a,l1))ans=disptoseg(l2.a,l1);
    if(ans>disptoseg(l2.b,l1))ans=disptoseg(l2.b,l1);
    return ans;
}

//测试用main函数 
#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int ans=0;
        line l[105];
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
            for(int j=0;j<i;j++)
            {
                if(intersect_in(l[i],l[j]))ans++;
            }
        }
        printf("%d\n",ans);
    }
}
