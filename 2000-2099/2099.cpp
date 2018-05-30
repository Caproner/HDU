#include<stdio.h>
void pri(int a)
{
    if(a<10)printf("0%d",a);
    else printf("%d",a);
}
int main()
{
    long long a;
    int b;
    while(1)
    {
        scanf("%lld %d",&a,&b);
        if(a==0&&b==0)break;
        a*=100;
        int i,p=0;
        for(i=0;i<100;i++)
        {
            if((a+i)%b==0)
            {
                if(p==0)
                {
                    p=1;
                }
                else printf(" ");
                pri(i);
            }
        }
        printf("\n");
    }
}
