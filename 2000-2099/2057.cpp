#include<stdio.h>
#include<string.h>
long long mi(int a,int m)
{
    long long ans=1;
    for(int i=0;i<m;i++)ans*=(long long)a;
    return ans;
}
void outt(long long a)
{
    long long i;
    char b[16];
    int p=0,j,k=0;
    if(a==0){printf("0");p=-1;}
    else if(a<0){a=-a;k=1;}
    while(a!=0)
    {
        i=a%16;
        a/=16;
        if(i<10)
        {
            b[p]='0';
            b[p]+=i;
            p++;
        }
        else
        {
            b[p]='A';
            i-=10;
            b[p]+=i;
            p++;
        }
    }
    if(k)printf("-");
    for(j=p;j>0&&p!=-1;j--)
    {
        printf("%c",b[j-1]);
    }
    printf("\n");
}
long long change(char s[16])
{
    int i,p=0,a=0,j;
    long long ans=0;
    if(s[0]=='-'){p++;a++;}
    if(s[0]=='+')p++;
    for(;s[p]!='\0';p++);
    for(i=p;i>0;i--)
    {
        if(s[i-1]=='-'||s[i-1]=='+')break;
        else if(s[i-1]<='9'&&s[i-1]>='0')j=s[i-1]-'0';
        else if(s[i-1]<='Z'&&s[i-1]>='A')j=s[i-1]-'A'+10;
        else return -1;
        ans+=((long long)(j)*mi(16,p-i));
    }
    if(a)ans=-ans;
    return ans;
}
int main()
{
    char s1[16],s2[16];
    long long a,b;
    while(scanf("%s %s",s1,s2)==2)
    {
        a=change(s1);
        b=change(s2);
        a+=b;
        outt(a);
    }
    return 0;
}
