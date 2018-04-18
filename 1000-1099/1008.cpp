#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int t=0,f=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            int p=a-f;
            if(p>=0)t+=(p*6);
            else t+=(-p*4);
            f=a;
            t+=5;
        }
        printf("%d\n",t);
    }
}
