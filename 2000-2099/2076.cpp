#include<stdio.h>
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double h,m,s;
        scanf("%lf %lf %lf",&h,&m,&s);
        double p1,p2;
                if(h>12)h=h-12;
        p1=(h+m/60+s/3600)*30;
                //if(p1>360)p1-=360;
        p2=(m+s/60)*6;
        double p=p2-p1;
        if(p<0)p=-p;
        if(p>180)p=360-p;
        int ans=(int)p;
        //printf("%lf ",p);
        printf("%d\n",ans);
    }
}    
