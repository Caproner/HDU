#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,len,a1,e1,i1,o1,u1;
    char c[101],d;
    scanf("%d",&n);
    d=getchar();
    for(i=0;i<n;i++)
    {
        a1=0;
        e1=0;
        i1=0;
        o1=0;
        u1=0;
        gets(c);
        len=strlen(c);
        for(j=0;j<len;j++)
        {
            if(c[j]=='a')a1++;
            else if(c[j]=='e')e1++;
            else if(c[j]=='i')i1++;
            else if(c[j]=='o')o1++;
            else if(c[j]=='u')u1++;
            else;
        }
        if(i!=0)printf("\n");
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a1,e1,i1,o1,u1);
    }
    return 0;
}
