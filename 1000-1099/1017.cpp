#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int cas=1,n,m;
        while(scanf("%d%d",&n,&m)==2)
        {
            if(n==0&&m==0)break;
            int count=0;
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<i;j++)
                {
                    int p=(j*j)+(i*i)+m,q=i*j;
                    if(p%q==0)count++;
                }
            }
            printf("Case %d: %d\n",cas++,count);
        }
        if(t)printf("\n");
    }
}
