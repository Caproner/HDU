#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,len,ans;
    char c[10000001];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        ans=0;
        gets(c);
        len=strlen(c);
        for(i=0;i<len;i++)if(c[i]<0)ans++;
        ans=(ans+1)/2;
        printf("%d\n",ans);
    }
    return 0;
}
