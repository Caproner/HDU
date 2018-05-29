#include<iostream>
#include<cstring>
//#include<cstdio>
using namespace std;
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[100];
        memset(a,0,sizeof(a));
        for(int i=0;i<k;i++)
        {
            int b1,b2;
            cin>>b1>>b2;
            a[b1]+=b2;
        }
        int c1[100],c2[100];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=a[1];i++)c1[i]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=a[i]&&j*i<=n;j++)
            {
                for(int kk=0;kk<=n&&c1[kk]!=0;kk++)
                {
                    c2[kk+j*i]+=c1[kk];
                }
            }
            for(int j=0;j<=n&&(c1[j]!=0||c2[j]!=0);j++)
            {
                c1[j]+=c2[j];
                c2[j]=0;
            }
        }
        cout<<c1[n]<<endl;
    }
}
