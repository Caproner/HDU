#include<bits/stdc++.h>
using namespace std;
int main()
{
    double d,t;
    int r,cas=1;
    while(scanf("%lf%d%lf",&d,&r,&t)==3)
    {
        if(r==0)break;
        printf("Trip #%d: %.2lf %.2lf\n",cas++,(d*3.1415927/12.0/5280.0)*r,((d*3.1415927/12.0/5280.0)*r)/t*3600);
    }
}
