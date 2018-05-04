#include<bits/stdc++.h>
using namespace std;
char s[100005];
bool c[100005];
bool check()
{
    int len=strlen(s);
    bool ans=false;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            c[i]=true;
            ans=true;
        }
        else c[i]=false;
    }
    if(!ans)return false;
    for(int i=2;i<len;i++)
        if((c[i]==c[i-1])&&(c[i]==c[i-2]))return false;
    for(int i=1;i<len;i++)
    {
        if(s[i]=='e'||s[i]=='o')continue;
        if(s[i]==s[i-1])return false;
    }
    return true;
}
int main()
{
    while(scanf("%s",s)==1)
    {
        if(strcmp(s,"end")==0)break;
        printf("<%s> is ",s);
        if(!check())printf("not ");
        printf("acceptable.\n");
    }
}
