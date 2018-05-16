#include<bits/stdc++.h>
using namespace std;
struct BigInteger
{
    int a[10005];
    int len;
    void init(char *s,int n)
    {
        memset(a,0,sizeof(a));
        while(n>0&&s[0]=='0')
        {
            s++;
            n--;
        }
        len=n;
        for(int i=0;i<n;i++)
            a[n-i-1]=(s[i]-'0');
    }
    void print(int p)
    {
        for(int i=len-1;i>=p;i--)
            printf("%d",a[i]);
        //if(len<=p)printf("0");
        int pp=0;
        while(pp<len&&a[pp]==0)pp++;
        if(pp>=p)return;
        printf(".");
        for(int i=p-1;i>=pp;i--)
            printf("%d",a[i]);
    }
    BigInteger operator * (BigInteger b)
    {
        BigInteger c;
        char s[2]="0";
        c.init(s,1);
        for(int i=0;i<b.len;i++)
        {
            for(int j=0;j<len;j++)
            {
                c.a[j+i]+=(a[j]*b.a[i]);
                if(c.len<=j+i)c.len=j+i+1;
            }
        }
        int p=0;
        for(int i=0;p||i<c.len;i++)
        {
            c.a[i]+=p;
            p=c.a[i]/10;
            c.a[i]%=10;
            if(i==c.len)c.len++;
        }
        return c;
    }
};
BigInteger a,b;
char s[10005];
int main()
{
    int n;
    while(scanf("%s",s)==1)
    {
        scanf("%d",&n);
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        int len=strlen(s);
        int p;
        for(p=len-1;p>=0&&s[p]!='.';p--);
        if(p<0)p=0;
        else
        {
            int pp=p;
            while(p<len)
            {
                s[p]=s[p+1];
                p++;
            }
            p=len-1-pp;
            len--;
        }
        a.init(s,len);
        b.init(s,len);
        for(int i=1;i<n;i++)
            a=a*b;
        a.print(p*n);
        printf("\n");
    }
}
