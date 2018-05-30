#include<stdio.h>
int main()
{
    int n,a,b,c,d,p,e,f,g;
    while(1)
    {
        p=0;
        scanf("%d",&n);
        if(n==0)break;
        a=n%10;
        b=(n%100-a)/10;
        c=(n%1000-n%100)/100;
        d=(n%10000-n%1000)/1000;
        e=a+b+c+d;
        a=n%16;
        b=(n%256-a)/16;
        c=(n%4096-n%256)/256;
        d=(n%65536-n%4096)/4096;
        f=a+b+c+d;
        a=n%12;
        b=(n%144-a)/12;
        c=(n%1728-n%144)/144;
        d=(n%20736-n%1728)/1728;
        g=a+b+c+d;
        if(e==f&&f==g)p=1;
        if(p)printf("%d is a Sky Number.\n",n);
        else printf("%d is not a Sky Number.\n",n);
    }
}
