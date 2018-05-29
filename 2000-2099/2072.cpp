#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

map<string,int> mp;

int main()
{
	string s;
	while(getline(cin,s))
	{
		if(s[0]=='#')break;
		mp.clear();
		int pos=0;
		while((pos<s.length())&&(!islower(s[pos])))
		{
			pos++;
		}
		while(pos<s.length())
		{
			string p;
			while((pos<s.length())&&(islower(s[pos])))
			{
				p+=s[pos++];
			}
			mp[p]++;
			while((pos<s.length())&&(!islower(s[pos])))
			{
				pos++;
			}
		}
		cout<<mp.size()<<endl;
	}
	return 0;
}
