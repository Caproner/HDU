#include<cstdio>
#include<cstring>
int main()
{
    char c[10005];
    while(scanf("%s",c)==1)
    {
        if(c[0]=='0'&&c[1]=='\0')break;
        int ans=0;
        for(int i=0;c[i]!='\0';i++)ans+=(c[i]-'0');
        while(ans>9)
        {
            int p=0;
            while(ans)
            {
                p+=ans%10;
                ans/=10;
            }
            ans=p;
        }
        printf("%d\n",ans);
    }
}
