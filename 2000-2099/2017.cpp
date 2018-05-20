#include<stdio.h>
#include<string.h>
int main()
{
    int n,len,i,j,ans;
    char a;
    scanf("%d",&n);
    a=getchar();
    for(i=0;i<n;i++)
    {
        ans=0;
        while(1)
        {
            a=getchar();
            if(a=='\n')break;
            if(a>='0'&&a<='9')ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
