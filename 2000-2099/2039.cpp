#include<stdio.h>
int main()
{
    double a,b,c;
    int m;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        if(a>=b+c||b>=a+c||c>=a+b)printf("NO\n");
        else printf("YES\n");
    }
}
