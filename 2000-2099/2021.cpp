#include<stdio.h>
int min(int b1,int b2,int b3,int b4,int b5,int b6)
{
    int i,p=b1,a[5]={b2,b3,b4,b5,b6};
    for(i=0;i<5;i++)
    {
        if((p>a[i]&&a[i]!=-1)||p==-1)p=a[i];
    }
    return p;
}
int main()
{
    int n,a,i,b[1000000],ans,p,j;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        ans=0;
        b[0]=0;
        b[1]=1;
        p=2;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a<p)ans+=b[a];
            else
            {
                for(;p<=a;p++)b[p]=min(p-100<0?-1:b[p-100],p-50<0?-1:b[p-50],p-10<0?-1:b[p-10],p-5<0?-1:b[p-5],p-2<0?-1:b[p-2],p-1<0?-1:b[p-1])+1;
                ans+=b[a];
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}

