#include<stdio.h>
int main()
{
    int t;
    while(scanf("%d",&t)&&t!=0)
    {
        int sum;
        scanf("%d",&sum);
        t--;
        while(t--)
        {
            int a;
            scanf("%d",&a);
            sum^=a;
        }
        printf("%d\n",sum);
    }
    return 0;
}
