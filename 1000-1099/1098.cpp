#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a=0;
        for(;a<65;a++)
        {
            long long p=18+n*a;
            if(p%65!=0)continue;
            p=5*pow(2,13)+13*pow(2,5)+2*n*a;
            if(p%65!=0)continue;
            p=5*pow(2,13)+13*pow(2,5)+2*n*a;
            if(p%65!=0)continue;
            break;
        }
        if(a==65)cout<<"no"<<endl;
        else cout<<a<<endl;
    }
}
