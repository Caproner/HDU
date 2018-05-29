#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("data.in","r",stdin);    
    int n,k=0;
    char a,b;
    while(scanf("%d %c %c",&n,&a,&b)==3)
    {
        if(k)printf("\n");
        if(n==1)
        {
            printf("%c\n",a);
            k=1;
            continue;
        }
        int i,j,p=(n/2)%2==1?1:0;
        char c[82][82];
        for(i=1;i<=n;i++)
        {
            if(p)
            {
                if(i%2==0)c[(n/2)+1][i]=a;
                else c[(n/2)+1][i]=b;
            }
            else
            {
                if(i%2==0)c[(n/2)+1][i]=b;
                else c[(n/2)+1][i]=a;
            }
        }
        c[1][1]=' ';
        c[1][n]=' ';
        c[n][1]=' ';
        c[n][n]=' ';
        if(p)for(i=2;i<n;i++){c[1][i]=b;c[n][i]=b;}
        else for(i=2;i<n;i++){c[1][i]=a;c[n][i]=a;}
        for(i=n/2;i>1;i--)
        {
            for(j=1;j<=n;j++)c[i][j]=c[i+1][j];
            char po=c[i+1][(n/2)+1];
            if(po==b)po=a;
            else po=b;
            for(j=(n/2)+1;j>=i;j--)
            {
                c[i][j]=po;
                c[i][n+1-j]=po;
            }
                        for(j=1;j<=n;j++)c[n+1-i][j]=c[i][j];
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%c",c[i][j]);
            printf("\n");
        }
        k=1;
    }
}  
