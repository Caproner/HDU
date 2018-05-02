#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int p;
            scanf("%d",&p);
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        printf("%d\n",v[(n+1)/2]);
    }
}
