#include<bits/stdc++.h>
using namespace std;
struct bint
{
    int a[1005];
    int top;
    void init(int b)
    {
        a[0]=b;
        top=1;
    }
    bint operator *(int b)
    {
        bint c;
        c.top=top;
        int p=0;
        for(int i=0;i<c.top||p;i++)
        {
            if(i==c.top)c.a[c.top++]=0;
            if(i<top)c.a[i]=a[i]*b+p;
            else c.a[i]=p;
            p=c.a[i]/10;
            c.a[i]%=10;
        }
        return c;
    }
    bint operator +(int b)
    {
        bint c=*this;
        c.a[0]=a[0]+b;
        int p=c.a[0]/10;
        c.a[0]%=10;
        int i=1;
        while(p)
        {
            if(i==c.top)c.a[c.top++]=0;
            if(i<top)c.a[i]=a[i]+p;
            else c.a[i]=p;
            p=c.a[i]/10;
            c.a[i]%=10;
            i++;
        }
        return c;
    }
    bint operator -(int b)
    {
        bint c=*this;
        c.top=top;
        c.a[0]=a[0]-b;
        int p=0;
        if(c.a[0]<0)
        {
            c.a[0]+=10;
            p++;
        }
        int i=1;
        while(p)
        {
            c.a[i]=a[i]-1;
            p=0;
            if(c.a[i]<0)
            {
                c.a[i]+=10;
                p++;
            }
            i++;
        }
        if(c.a[c.top-1]==0)c.top--;
        return c;
    }
    void print()
    {
        for(int i=top-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
}a[1005];
void init()
{
    a[1].init(0);
    a[2].init(1);
    a[3].init(1);
    for(int i=4;i<=1000;i+=2)
    {
        a[i]=a[i-1]*2+1;
        a[i+1]=a[i]*2-1;
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)==1)
        a[n].print();
}
