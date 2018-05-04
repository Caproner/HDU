#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double d;
    scanf("%d%lf",&n,&d);
    int a=0;
    char s[10005];
    while(scanf("%d:",&a)==1)
    {
        double t=0;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='-')flag=true;
            else
                t=t+((s[0]-'0')*3600)+((s[2]-'0')*600)+((s[3]-'0')*60)+((s[5]-'0')*10)+(s[6]-'0');
        }
        printf("%3d: ",a);
        if(flag)
        {
            printf("-\n");
            continue;
        }
        t/=d;
        t+=0.5;
        long long ans=t;
        printf("%lld:%02lld min/km\n",ans/60,ans%60);
    }
}
