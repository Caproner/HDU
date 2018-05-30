#include<stdio.h>
int main()
{
    double a,b,s=0;
    char c[100000];
    while(scanf("%s",c)==1)
    {
        scanf("%lf %lf",&a,&b);
        s+=(a*b);
    }
    printf("%.1lf\n",s);
}
