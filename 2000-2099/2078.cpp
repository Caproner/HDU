#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans;
		scanf("%d",&ans);
		for(int i=1;i<n;i++)
		{
			int p;
			scanf("%d",&p);
			ans=min(ans,p);
		}
		ans=100-ans;
		ans=ans*ans;
		printf("%d\n",ans);
	}
	return 0;
}
