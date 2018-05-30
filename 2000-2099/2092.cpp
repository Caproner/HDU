#include<stdio.h>
int answer(int a,int b,int m)
{
    if(a*b==m)return 1;
    else if(a*b<m)return 0;
    else return answer(a-1,b+1,m);
}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)break;
        int a=n/2;
        int b=n-a;
        int ans=answer(a,b,m);//递推求出是否含有此值
        if(ans)printf("Yes\n");
        else printf("No\n"); 
    }
}
