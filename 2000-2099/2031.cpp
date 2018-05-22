#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,a[100],i,p,z;
    while(scanf("%d %d",&n,&m)==2)
    {
        p=0;
        z=0;
        a[p]=0;
        if(n<0)
        {
            n=-n;
            z=1;
        }
        while(n!=0)
        {
            a[p]=n%m;
            n=n/m;
            p++;
        }
        if(z)printf("-");
        p--;
        while(p>-1)
        {
            if(a[p]<10)printf("%d",a[p]);
            else printf("%c",a[p]-10+'A');
            p--;
        }
        printf("\n");
    }
    return 0;
}
