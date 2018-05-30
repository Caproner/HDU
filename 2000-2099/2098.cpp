#include <bits/stdc++.h>

using namespace std;

vector<int> a;
bool s[10005];

void init()
{
	memset(s,0,sizeof(s));
	for(int i=2;i<10000;i++)
	{
		if(s[i])continue;
		a.push_back(i);
		for(int j=i+i;j<10000;j+=i)
			s[j]=true;
	}
}

int main()
{
	init();
    int b;
    while(1)
    {
        scanf("%d",&b);
        if(b==0)break;
        int i,j,p=0;
        for(j=0;a[j]<b;j++);
        j--;
        for(i=0;i<j;)
        {
            if(a[i]+a[j]==b)
            {
                p++;
                j--;
                i++;
            }
            else if(a[i]+a[j]>b)j--;
            else i++;
        }
        printf("%d\n",p);
    }
}
