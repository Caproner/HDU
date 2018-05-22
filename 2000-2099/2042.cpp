#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        int i=3;
        scanf("%d",&m);
        while(m--)
        {
            i--;
            i*=2;
        }
        printf("%d\n",i);
    }
}
