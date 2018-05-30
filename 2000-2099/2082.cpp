#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int a[100];
        memset(a,0,sizeof(a));
        for(int i=1;i<=26;i++)cin>>a[i];
        int c1[100],c2[100];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        int p=1;
        while(a[p]==0)p++;
        for(int i=0;i<=a[p];i++)c1[i*p]=1;
        for(int i=p+1;i<=50;i++)
        {
            for(int j=1;j<=a[i]&&j*i<=50;j++)
            {
                for(int kk=0;kk<=50;kk++)
                {
                    c2[kk+j*i]+=c1[kk];
                }
            }
            for(int j=0;j<=50;j++)
            {
                c1[j]+=c2[j];
                c2[j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=50;i++)ans+=c1[i];
        cout<<ans<<endl;
    }
}
