#include<stdio.h>
int main()
{
    int n,a;
    char c;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%c %d",&c,&a);
        getchar();
        if(c<='z'&&c>='a')a-=(c-'a'+1);
        else if(c<='Z'&&c>='A')a+=(c-'A'+1);
        else;
        printf("%d\n",a);
    }
}
