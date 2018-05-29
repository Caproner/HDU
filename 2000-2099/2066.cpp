#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int w[1005][1005];
int dijsktra(vector<int> b,vector<int> e)
{
    int l[1005];
    bool isw[1005]={0};
    for(int i=0;i<1005;i++)l[i]=-1;
    l[0]=0;
    for(int i=0;i<b.size();i++)l[b[i]]=0;
    int s=b[0];
    while(1)
    {
        isw[s]=true;
        for(int i=0;i<1005;i++)
        {
            if(s==i)continue;
            if(w[s][i]==-1)continue;
            if(l[i]==-1||l[i]>l[s]+w[s][i])l[i]=l[s]+w[s][i];
        }
        int min=-1,minp;
        for(int i=0;i<1005;i++)
        {
            if(l[i]==-1)continue;
            if(isw[i])continue;
            if(min==-1||l[i]<min)
            {
                min=l[i];
                minp=i;
            }
        }
        if(min==-1)break;
        s=minp;
    }
    int ans=l[e[0]];
    for(int i=1;i<e.size();i++)
    {
        if(l[e[i]]==-1)continue;
        if(ans==-1||ans>l[e[i]])ans=l[e[i]];
    }
    return ans;
}
int main()
{
    int s,t,d;
    while(cin>>t>>s>>d)
    {
        for(int i=0;i<1005;i++)
        {
            for(int j=0;j<1005;j++)
            {
                w[i][j]=-1;
            }
        }
        for(int i=0;i<t;i++)
        {
            int x,y,p;
            cin>>x>>y>>p;
            if(w[x][y]==-1||w[x][y]>p)
            {
                w[x][y]=p;
                w[y][x]=p;
            }
        }
        vector<int> ss,dd;
        for(int i=0;i<s;i++)
        {
            int p;
            cin>>p;
            ss.push_back(p);
        }
        for(int i=0;i<d;i++)
        {
            int p;
            cin>>p;
            dd.push_back(p);
        }
        cout<<dijsktra(ss,dd)<<endl;
    }
} 
