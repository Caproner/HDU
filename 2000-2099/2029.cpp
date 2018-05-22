#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,len,ans;
    char c[101];
    scanf("%d",&n);
    while(n--)
    {
        ans=1;
        scanf("%s",c);
        len=strlen(c);
        len--;
        for(i=0;i<len;i++)
        {
            if(c[i]!=c[len])
            {
                ans=0;
                break;
            }
            len--;
        }
        if(ans)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
