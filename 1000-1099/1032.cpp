#include<cstdio>
long long find(int n)
{
    long long cas=1;
    while(n!=1)
    {
        if(n&1)n=3*n+1;
        else n>>=1;
        cas++;
    }
    return cas;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        bool kp=false;
        if(a>b)
        {
            int t=a;
            a=b;
            b=t;
            kp=true;
        }
        int max=0;
        for(int i=a;i<=b;i++)
        {
            int p=find(i);
            if(max<p)max=p;
        }
        if(kp)
        {
            int t=a;
            a=b;
            b=t;
        }
        printf("%d %d %d\n",a,b,max);
    }
}
