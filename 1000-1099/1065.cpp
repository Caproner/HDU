#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        double r=sqrt(a*a+b*b);
        double s=3.1415926*r*r;
        int ans=ceil(s/100);
        printf("Property %d: This property will begin eroding in year %d.\n",cas++,ans);
    }
    printf("END OF OUTPUT.\n");
}
