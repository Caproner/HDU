#include<iostream>
using namespace std;
int main()
{
    int n,u,d;
    while(cin>>n>>u>>d&&(n||u||d))
    {
        int t=0;
        while(n>0)
        {
            n-=u;
            t++;
            if(n<=0)break;
            n+=d;
            t++;
        }
        cout<<t<<endl;
    }
}