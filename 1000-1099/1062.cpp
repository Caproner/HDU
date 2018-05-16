#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string c,ss;
        getline(cin,c);
        stringstream s;
        s<<c;
        int p=0;
        while(s>>ss)
        {
            reverse(ss.begin(),ss.end());
            while(c[p]==' ')
            {
                cout<<' ';
                p++;
            }
            cout<<ss;
            p+=ss.length();
        }
        for(;p<c.length();p++)cout<<' ';
        cout<<endl;
    }
}

