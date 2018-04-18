#include<cstdio>
#include<cstring>
using namespace std;
int a[1001],b[1001];
void add()
{
    int i,p=0;
    for(i=0;a[i]!=-1;i++)
    {
        if(b[i]!=-1)a[i]+=(b[i]+p);
        else a[i]+=p;
        p=0;
        if(a[i]>9)
        {
            a[i]-=10;
            p=1;
        }
    }
    for(;b[i]!=-1;i++)
    {
        a[i]=b[i]+p;
        p=0;
        if(a[i]>9)
        {
            a[i]-=10;
            p++;
        }
    }
    if(p)a[i]=1;
}
int main()
{
    //freopen("data.in","r",stdin);
    int n,i,ok=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(ok)printf("\n");
        for(int j=0;j<1001;j++)
        {
            a[j]=-1;
            b[j]=-1;
        }
        char c[1001],d[1001];
        scanf("%s %s",c,d);
        int lenc=strlen(c),lend=strlen(d);
        for(int j=lenc-1,k=0;j>-1;j--,k++)a[k]=c[j]-'0';
        for(int j=lend-1,k=0;j>-1;j--,k++)b[k]=d[j]-'0';
        add();
        printf("Case %d:\n",i+1);
        printf("%s + %s = ",c,d);
        for(int j=1000;j>-1;j--)
        {
            if(a[j]!=-1)printf("%d",a[j]);
        }
        printf("\n");
        ok=1;
    }
}
