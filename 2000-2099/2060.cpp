#include<stdio.h>
int main()
{
    int a,b,c,n;
    scanf("%d",&n);
    while(n--)
    {
        int i;
        scanf("%d %d %d",&a,&b,&c);
        for(i=a;i>6;i--)b+=8;
        switch(i)
        {
            case 1:b+=7;break;
            case 2:b+=13;break;
            case 3:b+=18;break;
            case 4:b+=22;break;
            case 5:b+=25;break;
            case 6:b+=27;break;
            default:;
        }
        if(b<c)printf("No\n");
        else printf("Yes\n");
    }
}
