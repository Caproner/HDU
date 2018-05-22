#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,a,len;
    char c[51];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",c);
        a=0;
        len=strlen(c);
        for(i=0;i<len;i++)if(c[i]>='a'&&c[i]<='z')
        {
            a++;
            break;
        }
        for(i=0;i<len;i++)if(c[i]>='A'&&c[i]<='Z')
        {
            a++;
            break;
        }
        for(i=0;i<len;i++)if(c[i]>='0'&&c[i]<='9')
        {
            a++;
            break;
        }
        for(i=0;i<len;i++)if(c[i]=='~'||c[i]=='!'||c[i]=='@'||c[i]=='#'||c[i]=='$'||c[i]=='%'||c[i]=='^')
        {
            a++;
            break;
        }
        if(a>2&&len>7&&len<17)printf("YES\n");
        else printf("NO\n");
    }
}
