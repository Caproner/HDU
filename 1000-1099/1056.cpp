#include<iostream>
using namespace std;
double ans[300];
int main()
{
    ans[0]=0;
    for(int i=1;i<300;i++)
    {
        double p=1.0/(i+1);
        ans[i]=ans[i-1]+p;
    }
    double n;
    while(cin>>n)
    {
        if(n<0.001)break;
        int i;
        for(i=1;i<300;i++)
        {
            if(n<=ans[i])break;
        }
        cout<<i<<" card(s)"<<endl;
    }
}