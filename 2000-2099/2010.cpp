#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,i,a,b,c,p;
    while(scanf("%d %d",&m,&n)==2)
    {
        p=0;
        for(i=m;i<=n;i++)
        {
            a=i/100;
            c=i%10;
            b=(i-c-(a*100))/10;
            if(i==a*a*a+b*b*b+c*c*c)
            {
                if(p==0)printf("%d",i);
                else printf(" %d",i);
                p=1;
            }
        }
        if(!p)printf("no");
        printf("\n");
    }
    return 0;
}
