#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool compare(char a,char b)
{
    return a>b;
}
char c[10];
long long calcu()
{
    long long ans=c[0]-'A'+1;
    ans-=(c[1]-'A'+1)*(c[1]-'A'+1);
    ans+=(c[2]-'A'+1)*(c[2]-'A'+1)*(c[2]-'A'+1);
    ans-=(c[3]-'A'+1)*(c[3]-'A'+1)*(c[3]-'A'+1)*(c[3]-'A'+1);
    ans+=(c[4]-'A'+1)*(c[4]-'A'+1)*(c[4]-'A'+1)*(c[4]-'A'+1)*(c[4]-'A'+1);
    return ans;
}
long long n;
char cans[10];
bool ise;
void dfs(char s[100005],int len,int sp,int p,bool isu[100005])
{
    if(ise)return;
    isu[sp]=true;
    c[p]=s[sp];
    if(p==4)
    {
        int ans=calcu();
        if(ans==n)
        {
            ise=true;
            for(int i=0;i<5;i++)cans[i]=c[i];
            cans[5]='\0';
            isu[sp]=false;
            return;
        }
    }
    else
    {
        p++;
        for(int i=0;i<len;i++)
        {
            if(!isu[i])dfs(s,len,i,p,isu);
        }
    }
    isu[sp]=false;
}
int main()
{
    char s[100005];
    while(cin>>n>>s)
    {
        if(n==0&&s[0]=='E'&&s[1]=='N'&&s[2]=='D')break;
        ise=false;
        int len=strlen(s);
        sort(s,s+len,compare);
        bool isu[100005]={0};
        for(int i=0;i<len;i++)dfs(s,len,i,0,isu);
        if(ise)cout<<c<<endl;
        else cout<<"no solution"<<endl;
    }
}
