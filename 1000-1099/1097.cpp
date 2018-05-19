#include<iostream>
using namespace std;
int solve(int p,int n)
{
    p=p%10;
    if(p==0||p==1||p==5||p==6)return p;
    else if(p==2)
    {
        int k=n%4;
        if(k==0)return 6;
        else if(k==1)return 2;
        else if(k==2)return 4;
        else return 8;
    }
    else if(p==3)
    {
        int k=n%4;
        if(k==0)return 1;
        else if(k==1)return 3;
        else if(k==2)return 9;
        else return 7;
    }
    else if(p==7)
    {
        int k=n%4;
        if(k==0)return 1;
        else if(k==1)return 7;
        else if(k==2)return 9;
        else return 3;
    }
    else if(p==8)
    {
        int k=n%4;
        if(k==0)return 6;
        else if(k==1)return 8;
        else if(k==2)return 4;
        else return 2;
    }
    else if(p==4)
    {
        int k=n%2;
        if(k==0)return 6;
        else return 4;
    }
    else
    {
        int k=n%2;
        if(k==0)return 1;
        else return 9;
    }
}
int main()
{
    int n,m;
    while(cin>>n>>m)cout<<solve(n,m)<<endl;
}
