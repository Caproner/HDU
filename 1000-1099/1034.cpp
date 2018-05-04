#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
bool check(int n)
{
    for(int i=1;i<n;i++)
        if(a[i]!=a[0])return false;
    return true;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        while(!check(n))
        {
            for(int i=0;i<n;i++)
            {
                a[i]/=2;
                b[(i+1)%n]=a[i];
            }
            for(int i=0;i<n;i++)
            {
                a[i]+=b[i];
                if(a[i]&1)a[i]++;
            }
            ans++;
        }
        printf("%d %d\n",ans,a[0]);
    }
}
