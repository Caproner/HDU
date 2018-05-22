#include<stdio.h>
int main()
{
    int a,b,i,c;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==0&&b==0)break;
        c=a;
        for(i=1;i<b;i++)
        {
            a=a%1000;
            a=a*c;
        }
        a=a%1000;
        printf("%d\n",a);
    }
}
