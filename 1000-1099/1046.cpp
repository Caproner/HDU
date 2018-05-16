#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        double ans=n*m;
        if((n&1)&&(m&1))ans+=(sqrt(2)-1);
        printf("Scenario #%d:\n%.2lf\n\n",cas++,ans);
    }
}
