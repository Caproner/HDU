#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool compare(int a,int b)
{
    return abs(a)>abs(b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    while(cin>>n&&n)
    {
        int a[100];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n,compare);
        for(int i=0;i<n;i++)
        {
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }
}
