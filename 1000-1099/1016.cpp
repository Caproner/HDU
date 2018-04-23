#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
vector<int> v;
int prime[12]={2,3,5,7,11,13,17,19,23,29,31,37};
bool isp(int p)
{
    for(int i=0;i<12;i++)if(p==prime[i])return true;
    return false;
}
void pri(int n,set<int> s,int p=-1)
{
    if(p==-1)
    {
        v.push_back(1);
        s.erase(1);
        pri(n-1,s,1);
    }
    else
    {
        for(set<int>::iterator it=s.begin();it!=s.end();it++)
        {
            if(!isp(p+*it))continue;
            v.push_back(*it);
            if(n==1&&isp(*it+1))
            {
                for(vector<int>::iterator i=v.begin();i!=v.end();i++)
                {
                    if(i!=v.begin())putchar(' ');
                    printf("%d",*i);
                }
                printf("\n");
            }
            set<int> sp=s;
            sp.erase(*it);
            pri(n-1,sp,*it);
            v.erase(v.end()-1);
        }
    }
}
int main()
{
    int n,t=1;
    while(cin>>n)
    {
        v.clear();
        cout<<"Case "<<t++<<":"<<endl;
        set<int> s;
        for(int i=0;i<n;i++)s.insert(i+1);
        pri(n,s);
        cout<<endl;
    }
}
