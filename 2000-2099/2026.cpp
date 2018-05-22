#include<stdio.h>
#include<string.h>
int main()
{
    char b,c[101];
    int i,len,d=0;
    while(gets(c)!=NULL)
    {
        len=strlen(c);
        c[0]-=32;
        for(i=1;i<len;i++)if(c[i-1]==' '&&c[i]!=' ')c[i]-=32;
        printf("%s\n",c);
    }
    return 0;
}
