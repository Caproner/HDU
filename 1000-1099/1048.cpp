#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s!="START"&&s!="END"&&s!="ENDOFINPUT")
        {
            for(int i=0;i<s.length();i++)
            {
                if(s[i]<='Z'&&s[i]>='A')
                {
                    s[i]-=5;
                    if(s[i]<'A')s[i]+=26;
                }
            }
            cout<<s<<endl;
        }
    }
}