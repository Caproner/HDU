#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b[1000];
        scanf("%d",&a);
        for(int i=0;i<a;i++)scanf("%d",&b[i]);
        sort(b,b+a);
        for(int i=0;i<a;i++)
        {
            if(i)printf(" ");
            printf("%d",b[i]);
        }
        printf("\n");
    }
}
