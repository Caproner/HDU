#include<stdio.h>
int main()
{
    int n,a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        a%=100;
        b%=100;
        a+=b;
        a%=100;
        printf("%d\n",a);
    }
}
