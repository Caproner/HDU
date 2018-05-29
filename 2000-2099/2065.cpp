#include<iostream>
using namespace std;
int pow(int a,long long b)
{
    int r=1,base=a;
    while(b!=0)
    {
        if(b&1)
            r*=base;
        base*=base;
        r%=100;
        base%=100;
        b>>=1;
    }
    return r;
}
int main()
{
    int t;
    while(cin>>t)
    {
        if(t==0)break;
        for(int i=0;i<t;i++)
        {
            long long a;
            cin>>a;
            int res=pow(2,a-1);
            res=res*(res+1);
            res%=100;
            cout<<"Case "<<i+1<<": "<<res<<endl;
        }
        cout<<endl;
    }
}
