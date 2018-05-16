#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double ans=0;
    for(int i=0;i<12;i++)
    {
        double a;
        cin>>a;
        ans+=a;
    }
    cout<<'$'<<setiosflags(ios::fixed)<<setprecision(2)<<ans/12<<endl;
}
