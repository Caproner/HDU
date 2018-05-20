#include<stdio.h>
int main()
{
    int n,z,l,f,i;
    double a;
    while(1)
    {
        z=0;
        l=0;
        f=0;
        scanf("%d",&n);
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a);
            if(a<0)f++;
            else if(a>0)z++;
            else l++;
        }
        printf("%d %d %d\n",f,l,z);
    }
    return 0;
}
