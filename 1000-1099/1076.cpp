#include<iostream>
using namespace std;
int solve(int y,int n)
{
    if(n==0)
    {
        if(y%400!=0&&y%100==0)y+=4;
        return y;
    }
    else
    {
        y+=4;
        if(y%400!=0&&y%100==0)y+=4;
        return solve(y,n-1);
    }
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int y,n;
        cin>>y>>n;
        while(y%4!=0)y++;
        if(y%400!=0&&y%100==0)y+=4;
        cout<<solve(y,n-1)<<endl;
    }
}
