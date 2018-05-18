#include<iostream>
#include<string>
using namespace std;
struct milk
{
    string name;
    int p,n;
    double ans;
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p=0;
        cin>>n;
        milk m[105];
        for(int i=0;i<n;i++)
        {
            cin>>m[i].name>>m[i].p>>m[i].n;
            int k=m[i].n/200;
            if(k>5)k=5;
            m[i].ans=(double)m[i].p/k;
            if(i&&(m[p].ans>m[i].ans||(m[p].ans==m[i].ans&&m[p].n<m[i].n)))p=i;
        }
        cout<<m[p].name<<endl;
    }
}
