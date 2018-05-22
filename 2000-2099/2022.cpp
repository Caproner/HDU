#include<stdio.h>
int abs(int i)
{
    if(i<0)i=-i;
    return i;
}
int main()
{    
    int a,b,c,i,p,pp;
    while(scanf("%d %d",&a,&b)==2)
    {
        for(i=0;i<a*b;i++)
        {
            if(i==0)
            {
                scanf("%d",&p);
                pp=1;
            }
            else
            {
                scanf("%d",&c);
                if(abs(c)>abs(p))
                {
                    p=c;
                    pp=i+1;
                }
            }
        }
        printf("%d %d %d\n",pp%b==0?pp/b:(pp/b)+1,pp%b==0?b:pp%b,p);
    }
    return 0;
}
