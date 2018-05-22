#include<stdio.h>
#include<string.h>
int main()
{    
    int i,j,max,len;
    char c[101];
    while(scanf("%s",c)==1)
    {
        len=strlen(c);
        max=0;
        for(i=0;i<len;i++)if(c[i]>max)max=c[i];
        for(i=0;i<len;i++)
        {
            printf("%c",c[i]);
            if(c[i]==max)printf("(max)");
        }
        printf("\n");
    }
    return 0;
}
