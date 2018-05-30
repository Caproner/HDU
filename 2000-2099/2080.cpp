#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846264338327950288
int main()
{
    //freopen("data.in","r",stdin);    
    int a;
    scanf("%d",&a);
    while(a--)
    {
        double x1,y1,x2,y2;
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        //x1+=0.05;
        //x2+=0.05;
        //y1+=0.05;
        //y2+=0.05;
        double c1=x1/(sqrt((x1*x1)+(y1*y1))),c2=x2/(sqrt((x2*x2)+(y2*y2))),s1=y1/(sqrt((x1*x1)+(y1*y1))),s2=y2/(sqrt((x2*x2)+(y2*y2)));
        double c=c1*c2+s1*s2;
        if(c>1)c=1;
        if(c<-1)c=-1;
        double ans=acos(c);
        printf("%.2lf\n",ans*180/PI);
    }
}   
