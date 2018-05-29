#include<stdio.h>
#include<string.h>
int main()
{
    char c[100000];
    while(gets(c)!=NULL)
    {
        if(c[0]=='#')break;
        int ans=0;
        int a[100000],p=0,len=strlen(c);
        for(int i=0;i<len;i++)
        {
            if(c[i]==' ')continue;
            a[p*2]=i;
            int j;
            for(j=i;c[j]!=' '&&c[j]!='\0';j++);
            a[p*2+1]=j;
            p++;
            i=j;
        }
        for(int i=0;i<p;i++)
        {
            char d[100000];
            int k=0,pp=1;
            for(int j=a[i*2];j<a[i*2+1];j++,k++)d[k]=c[j];
            d[k]='\0';
            for(int j=i+1;j<p;j++)
            {
                char e[100000];
                int kk=0;
                for(int jj=a[j*2];jj<a[j*2+1];jj++,kk++)e[kk]=c[jj];
                e[kk]='\0';
                if(strcmp(d,e)==0)
                {
                    pp=0;
                    break;
                }
            }
            if(pp)ans++;
        }
        printf("%d\n",ans);
    }
}
