#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("data.in","r",stdin);
    char a[1000],b[1000];
    while(scanf("%s %s",a,b)==2&&a[0]!='#')
    {
        int lena=strlen(a),lenb=strlen(b);
        int k=0,ans=0;
        while(k<lena)
        {
            if(lena-k<lenb)break;
            if(strncmp(a+k,b,lenb)==0)
            {
                ans++;
                k+=lenb;
            }
            else k++;
        }
        printf("%d\n",ans);
    }
}
