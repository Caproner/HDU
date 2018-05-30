#include<stdio.h>
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b[6000],c[6000],d[6000],j=1,q=1;
        scanf("%d",&a);
        for(int i=0;i<(a+1)*a/2;i++)
        {
            scanf("%d",&b[i]);
            c[i]=q;
            if(j==q)
            {
                j=1;
                q++;
            }
            else j++;
        }
        for(int i=((a+1)*a/2)-1;i>=0;i--)
        {
            if(c[i]==a)d[i]=b[i];
            else d[i]=max(d[i+c[i]],d[i+c[i]+1])+b[i];
        }
        printf("%d\n",d[0]);
    }
}
