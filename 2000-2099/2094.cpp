#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("data.in","r",stdin);
    int n,a[1000];
    while(scanf("%d",&n)==1&&n)
    {
            char c[2][1000][200];
        for(int i=0;i<n;i++)a[i]=1;
        for(int i=0;i<n;i++)scanf("%s %s",c[0][i],c[1][i]);
        int j,k,p=0;
        for(j=0;j<n;j++)
        {
            if(a[j]==0)continue;
            for(k=j+1;k<n;k++)
            {
                if(strcmp(c[0][j],c[0][k])==0&&a[k])a[k]=0;
            }
        }
        for(j=0;j<n;j++)
        {
            if(a[j]==0)continue;
            int pp=1;
            for(k=0;k<n;k++)
            {
                if(strcmp(c[0][j],c[1][k])==0)
                {
                    pp=0;
                    break;
                }
            }
            if(pp)p++;
        }
        if(p==1)printf("Yes\n");
        else printf("No\n");
    }
}
