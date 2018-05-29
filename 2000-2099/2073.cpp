#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("data.in","r",stdin);    
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x1,y1,x2,y2;
        double ans=0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        while(1)
        {
            if(x1+y1==x2+y2)
            {
                double bas=(double)x2-(double)x1;
                if(bas<0)bas=-bas;
                ans+=sqrt(bas*bas+bas*bas);
                printf("%.3lf\n",ans);
                break;
            }
            else
            {
                if(x1+y1>x2+y2)
                {
                    int t;
                    t=x1;
                    x1=x2;
                    x2=t;
                    t=y1;
                    y1=y2;
                    y2=t;
                }
                double bas=(double)y2;
                ans-=sqrt(bas*bas+bas*bas);
                int s1=x1+y1,s2=x2+y2;
                for(int j=(s2);j>(s1);j--)ans+=sqrt(2*(double)j*(double)j)+sqrt((double)j*(double)j+(double)(j-1)*(double)(j-1));
                x2=s1;
                y2=0;
            }
        }
    }
}    
