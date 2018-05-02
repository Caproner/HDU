#include<cstdio>
int main()
{
    int a;
    while(scanf("%d",&a)==1)
    {
        if((a-2)%4==0)printf("yes\n");
        else printf("no\n");
    }
}
