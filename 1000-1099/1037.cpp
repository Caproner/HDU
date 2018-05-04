#include<cstdio>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        int ans=180;
        if(a<168)ans=a;
        else if(b<168)ans=b;
        else if(c<168)ans=c;
        if(ans==180)printf("NO CRASH\n");
        else printf("CRASH %d\n",ans);
    }
}
