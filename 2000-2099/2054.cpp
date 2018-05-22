#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000000],b[1000000];
    int i,j;
    while(scanf("%s %s",a,b)==2)
    {
        if(strcmp(a,b)==0)printf("YES\n");
        else
        {
            i=0;
            for(j=0;a[j]!='.'&&b[j]!='.';j++)if(a[j]!=b[j])
            {
                i=1;
                break;
            }
            if(a[j]=='.')
            {
                if(b[j]!='.'&&b[j]!='\0')i=1;
                else if(b[j]=='\0')
                {
                    while(a[j]!='\0')
                    {
                        if(a[j]!='0'&&a[j]!='.')i=1;
                        j++;
                    }
                    if(i==0)
                    {
                        printf("YES\n");
                        continue;
                    }
                }
            }
            else if(b[j]=='.')
            {
                if(a[j]!='.'&&a[j]!='\0')i=1;
                else if(a[j]=='\0')
                {
                    while(b[j]!='\0')
                    {
                        if(b[j]!='0'&&b[j]!='.')i=1;
                        j++;
                    }
                    if(i==0)
                    {
                        printf("YES\n");
                        continue;
                    }
                }
            }
            else;
            if(i==0)
            {
                while(1)
                {
                    if(a[j]=='\0')
                    {
                        while(b[j]!='\0')
                        {
                            if(b[j]!='0')
                            {
                                i=1;
                                break;
                            }
                            j++;
                        }
                        break;
                    }
                    else if(b[j]=='\0')
                    {
                        while(a[j]!='\0')
                        {
                            if(a[j]!='0')
                            {
                                i=1;
                                break;
                            }
                            j++;
                        }
                        break;
                    }
                    else if(a[j]!=b[j])i=1;
                    j++;
                }
            }
            if(i)printf("NO\n");
            else printf("YES\n");
        }
    }    
}
