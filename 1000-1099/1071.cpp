#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(x2>x3)
        {
            double t=x2;
            x2=x3;
            x3=t;
            t=y2;
            y2=y3;
            y3=t;
        }
        double a,b,c,k,h;
        a=((y1-y2)*(x1-x3)-(y1-y3)*(x1-x2))/((x1*x1-x2*x2)*(x1-x3)-(x1*x1-x3*x3)*(x1-x2));
        b=-2*a*x1;
        c=y1-a*x1*x1-b*x1;
        k=(y2-y3)/(x2-x3);
        h=y2-k*x2;
        double f=(a*x3*x3*x3/3+b*x3*x3/2+c*x3)-(a*x2*x2*x2/3+b*x2*x2/2+c*x2);
        f-=((k*x3*x3/2+h*x3)-(k*x2*x2/2+h*x2));
        printf("%.2lf\n",f);
    }
}
