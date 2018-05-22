#include<stdio.h>
int main()
{
    int n,m,i,j;
    while(scanf("%d %d",&n,&m)==2)
    {
        printf("+");
        for(i=0;i<n;i++)printf("-");
        printf("+\n");
        for(i=0;i<m;i++)
        {
            printf("|");
            for(j=0;j<n;j++)printf(" ");
            printf("|\n");
        }
        printf("+");
        for(i=0;i<n;i++)printf("-");
        printf("+\n\n");
    }
}
