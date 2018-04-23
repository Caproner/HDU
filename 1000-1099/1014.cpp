#include<iostream>
#include<iomanip>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        cout<<setw(10)<<n<<setw(10)<<m;
        if(gcd(n,m)==1)cout<<"    Good Choice"<<endl<<endl;
        else cout<<"    Bad Choice"<<endl<<endl;
    }
}
