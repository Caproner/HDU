#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,j,i,k,ex;
    while(1)
    {
        scanf("%d %d",&m,&n);
        if(m==0&&n==0)break;
        ex=0;
        for(i=m;i<n+1;i++)
        {
            j=i*i+i+41;
            for(k=2;k<=sqrt((double)j);k++)
            {
                if(j%k==0)
                {
                    ex=1;
                    break;
                }
            }
            if(ex)break;
        }
        if(ex)printf("Sorry\n");
        else printf("OK\n");
    }
    return 0;
}
