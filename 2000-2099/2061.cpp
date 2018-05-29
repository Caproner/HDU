#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        double ans=0,ank=0;
        scanf("%d",&m);
        while(m--)
        {
            double c,s;
            char b[20];
            scanf("%s %lf %lf",b,&c,&s);
            if(s<60)ans=-1;
            if(ans!=-1)ans+=c*s;
            ank+=c;
        }
        if(ans==-1)printf("Sorry!\n");
        else printf("%.2lf\n",ans/ank);
        if(n!=0)printf("\n");
    }
}
