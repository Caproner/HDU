#include<stdio.h>
int p[21];
void left(int a)
{
    int i;
    for(i=a;i<20;i++)p[i]=p[i+1];
}
int main()
{
    int a;
    long long b;
    while(scanf("%d %lld",&a,&b)==2)
    {
        long long c=1;
        int i;
        for(i=0;i<20;i++)p[i]=i+1;
        for(i=1;i<a;i++)c=(c+1)*(i+1);
        c/=a;
        printf("%lld",p[(b-1)/c]);
        left((b-1)/c);
        while(c!=1)
        {
            b=((b-1)%c)+1;
            if(b==1)
            {
                c=1;
                break;
            }
            c--;
            a--;
            c/=a;
            b--;
            printf(" %lld",p[(b-1)/c]);
            left((b-1)/c);
        }
        printf("\n");
    }
}
