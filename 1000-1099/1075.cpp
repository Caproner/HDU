#include <bits/stdc++.h>

using namespace std;

map<string,string> mp;

char re[100005];

int main()
{
    while(scanf("%s",re)==1)
    {
        mp.clear();
        while(true)
        {
            scanf("%s",re);
            string sa=re;
            if(sa=="END")break;
            scanf("%s",re);
            string sb=re;
            mp[sb]=sa;
        }
        scanf("%s",re);
        getchar();
        while(true)
        {
            gets(re);
            string s=re,str;
            if(s=="END")break;
            for(int i=0;i<s.length();i++)
            {
                if((s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A'))
                    str+=s[i];
                else
                {
                    if(str.length()!=0)
                    {
                        if(mp.find(str)!=mp.end())printf("%s",mp[str].c_str());
                        else printf("%s",str.c_str());
                    }
                    str.clear();
                    printf("%c",s[i]);
                }
            }
            printf("\n");
        }
    }
}
