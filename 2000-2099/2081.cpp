#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("data.in","r",stdin);    
    int a;
    scanf("%d",&a);
    while(a--)
    {
        char c[11];
        scanf("%s",c);
        printf("6%c%c%c%c%c\n",c[6],c[7],c[8],c[9],c[10]);
    }
} 
