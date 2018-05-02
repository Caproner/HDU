#include<bits/stdc++.h>
using namespace std;
char s[10005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len=strlen(s),i=0;
        while(i<len)
        {
            char c=s[i];
            int cnt=0;
            while(i<len&&s[i]==c)
            {
                cnt++;
                i++;
            }
            if(cnt==1)printf("%c",c);
            else printf("%d%c",cnt,c);
        }
        printf("\n");
    }
}
