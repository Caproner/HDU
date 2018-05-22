#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,p,m,i,ans;
    scanf("%d",&m);
    while(m--)
    {
        ans=1;
        scanf("%d %d",&a,&b);
        p=1;
        for(i=2;i<=sqrt((double)a);i++)
        {
            if(a%i==0)
            {
                p+=i;
                p+=(a/i);
            }
        }
        if(p!=b)ans=0;
        else
        {
            p=1;
            for(i=2;i<sqrt((double)b);i++)
            {
                if(b%i==0)
                {
                    p+=i;
                    p+=(b/i);
                }
            }
            if(p!=a)ans=0;
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
}

