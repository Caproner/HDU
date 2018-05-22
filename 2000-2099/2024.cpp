#include<stdio.h>
#include<string.h>
int main()
{    
    int n,i,p,j;
    char c[51],d;
    scanf("%d",&n);
    d=getchar();
    for(i=0;i<n;i++)
    {
        p=1;
        c[0]=getchar();
        for(j=1;c[j-1]!='\n';j++)c[j]=getchar();
        if(!(c[0]=='_'||(c[0]<='z'&&c[0]>='a')||(c[0]<='Z'&&c[0]>='A')))p=0;
        else
        {
            for(j=0;c[j]!='\n';j++)
                if(!(c[j]=='_'||(c[j]<='9'&&c[j]>='0')||(c[j]<='z'&&c[j]>='a')||(c[j]<='Z'&&c[j]>='A')))
                {
                    p=0;
                    break;
                }
        }
        if(p)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
