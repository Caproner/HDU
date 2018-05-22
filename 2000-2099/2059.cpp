#include<iostream>
using namespace std;
int main()
{
    //freopen("data.in","r",stdin);
    double l;
    while(cin>>l)
    {
        int n;
        double c,t,vr,vt1,vt2,p[101];
        cin>>n>>c>>t>>vr>>vt1>>vt2;
        for(int i=0;i<n;i++)cin>>p[i+1];
        p[0]=0;
        p[n+1]=l;
        double dp[200],rans=l/vr;
        dp[0]=0;
        for(int i=1;i<=n+1;i++)
        {
            double max;
            for(int j=i-1;j>=0;j--)
            {
                double m=t;
                if(j==0)m=0;
                double ll=p[i]-p[j];
                if(ll>c)m+=((c/vt1)+((ll-c)/vt2));
                else m+=(ll/vt1);
                m+=dp[j];
                if(j==i-1||max>m)max=m;
            }
            dp[i]=max;
        }
        if(rans<dp[n+1])cout<<"Good job,rabbit!"<<endl;
        else cout<<"What a pity rabbit!"<<endl;
        //cout<<rans<<endl<<dp[n+1]<<endl;
    }
}
