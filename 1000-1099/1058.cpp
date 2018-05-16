#include<iostream>
#include<queue>
#include<string>
using namespace std;
long long s[6000],sp=2;
struct f
{
    long long n;
    int i;
    bool operator < (const f &a)const
    {
        return a.n<n;
    }
};
int main()
{
    s[1]=1;
    priority_queue<f> q;
    f k;
    k.n=2;k.i=2;
    q.push(k);
    k.n=3;k.i=3;
    q.push(k);
    k.n=5;k.i=5;
    q.push(k);
    k.n=7;k.i=7;
    q.push(k);
    while(!q.empty())
    {
        f p=q.top();
        q.pop();
        s[sp]=p.n;
        sp++;
        if(p.i<=2&&p.n*2<2000000001)
        {
            p.i=2;
            p.n*=2;
            q.push(p);
            p.n/=2;
        }
        if(p.i<=3&&p.n*3<2000000001)
        {
            p.i=3;
            p.n*=3;
            q.push(p);
            p.n/=3;
        }
        if(p.i<=5&&p.n*5<2000000001)
        {
            p.i=5;
            p.n*=5;
            q.push(p);
            p.n/=5;
        }
        if(p.i<=7&&p.n*7<2000000001)
        {
            p.i=7;
            p.n*=7;
            q.push(p);
            p.n/=7;
        }
    }
    int n;
    while(cin>>n&&n)
    {
        string ss="th";
        if(n%10==1&&n%100!=11)ss="st";
        if(n%10==2&&n%100!=12)ss="nd";
        if(n%10==3&&n%100!=13)ss="rd";
        cout<<"The "<<n<<ss<<" humble number is "<<s[n]<<"."<<endl;
    }
}