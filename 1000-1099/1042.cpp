#include<cstdio>
void plus(int a[100000],int b,int &len)
{
    int p=0;
    for(int i=0;i<len;i++)
    {
        a[i]=a[i]*b+p;
        if(a[i]>9)
        {
            p=a[i]/10;
            a[i]=a[i]%10;
        }
        else p=0;
        if(len-i==1&&p!=0)len++;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int a[100000]={0},len=1;
        a[0]=1;
        for(int i=1;i<=n;i++)plus(a,i,len);
        for(int i=len-1;i>=0;i--)printf("%d",a[i]);
        printf("\n");
    }
}
