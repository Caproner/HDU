#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s1[10],s2[10],s[10],ss[10];
int n,sp,s1p,ssp;
bool move[30];
bool dfs(int p)
{
    if(p==n*2)
    {
        if(ssp!=n)return false;
        for(int i=0;i<n;i++)
        {
            if(s2[i]!=ss[i])return false;
        }
        return true;
    }
    bool ans=false;
    if(sp!=0)
    {
        char ch=s[sp-1];
        sp--;
        ss[ssp]=ch;
        ssp++;
        bool ak=dfs(p+1);
        if(ak)move[p]=0;
        ans=ans||ak;
        ssp--;
        s[sp]=ch;
        sp++;
    }
    if(ans||s1p!=n)
    {
        s[sp]=s1[s1p];
        s1p++;
        sp++;
        bool ak=dfs(p+1);
        if(ak)move[p]=1;
        ans=ans||ak;
        s1p--;
        sp--;
    }
    return ans;
}
int main()
{
    while(scanf("%d%s%s",&n,s1,s2)==3)
    {
        sp=0;s1p=0;ssp=0;
        bool ans=dfs(0);
        if(ans)
        {
            printf("Yes.\n");
            for(int i=0;i<2*n;i++)
            {
                if(move[i])printf("in\n");
                else printf("out\n");
            }
        }
        else printf("No.\n");
        printf("FINISH\n");
    }
}
