#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long a,b;
}; 
map<char,node> mp;
stack<node> stk;
char s[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    mp.clear();
    for(int i=0;i<n;i++)
    {
        char c[4];
        node p;
        scanf("%s%lld%lld",c,&p.a,&p.b);
        mp[c[0]]=p;
    }
    while(~scanf("%s",s))
    {
        while(!stk.empty())
            stk.pop();
        int len=strlen(s);
        bool flag=true;
        long long ans=0;
        for(int i=0;flag&&i<len;i++)
        {
            if(s[i]==')')
            {
                node aa,bb;
                aa=stk.top();
                stk.pop();
                bb=stk.top();
                stk.pop();
//                printf("%lld %lld %lld %lld\n",bb.a,bb.b,aa.a,aa.b);
                if(bb.b!=aa.a)
                {
                    flag=false;
                    continue;
                }
                ans+=bb.a*bb.b*aa.b;
                bb.b=aa.b;
                stk.push(bb);
            }
            else if(s[i]=='(')continue;
            else stk.push(mp[s[i]]);
        }
        if(flag)printf("%lld\n",ans);
        else printf("error\n");
    }
}
