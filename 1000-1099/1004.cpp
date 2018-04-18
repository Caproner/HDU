#include<iostream>
#include<string>
using namespace std;
struct str
{
    string a;
    int n;
};
int main()
{
    str a[1000];
    int n,p=0;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<1000;i++)a[i].n=0;
        while(n--)
        {
            string c;
            cin>>c;
            int ok=1;
            for(int i=0;i<p;i++)
            {
                if(c==a[i].a)
                {
                    a[i].n++;
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                a[p].a=c;
                a[p].n=1;
                p++;
            }
        }
        int k=0;
        for(int i=0;i<p;i++)
        {
            if(a[k].n<a[i].n)k=i;
        }
        cout<<a[k].a<<endl;
    }
}
