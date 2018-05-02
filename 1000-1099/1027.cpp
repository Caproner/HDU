#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool vis[1005];
void CantorExpansion(int n,int m)
{
    memset(vis,0,sizeof(vis));
    int k=1,kk=1,top=0;
    while(kk<n&&k<=m)
    {
        k*=kk;
        kk++;
    }
    kk--;
    int nn=n;
    while(kk+1<nn)
    {
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                a[top++]=i+1;
                vis[i]=true;
                break;
            }
        }
        nn--;
    }
    while(kk>=0)
    {
        int p1=m/k,p2=m%k;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(p1==0)
                {
                    a[top++]=i+1;
                    vis[i]=true;
                    break;
                }
                p1--;
            }
        }
        m=p2;
        if(kk!=0)k/=kk;
        kk--;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        CantorExpansion(n,m-1);
        for(int i=0;i<n;i++)
        {
            if(i)printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
}
