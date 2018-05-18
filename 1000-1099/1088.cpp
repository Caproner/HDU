#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("1.out","w",stdout);
    string s;
    int p=0;
    while(cin>>s)
    {
        if(s[0]!='<')
        {
            if(p!=0)
            {
                if(p+s.length()+1>80)
                {
                    cout<<endl;
                    p=0;
                }
                else
                {
                    p++;
                    cout<<' ';
                }
                cout<<s;
                p+=s.length();
            }
            else
            {
                cout<<s;
                p=s.length();
            }
        }
        else if(s[1]=='b')
        {
            p=0;
            cout<<endl;
        }
        else
        {
            if(p!=0)cout<<endl;
            p=0;
            for(int i=0;i<80;i++)cout<<'-';
            cout<<endl;
        }
    }
    cout<<endl;
}
