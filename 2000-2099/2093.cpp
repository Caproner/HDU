#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct person
{
    string name;
    int solve,time;
};
bool compare(person a,person b)
{
    return a.solve>b.solve||(a.solve==b.solve&&(a.time<b.time||(a.time==b.time&&a.name<b.name)));
}
int main()
{
    int n,ft;
    scanf("%d%d",&n,&ft);
    person a[10005];
    int pp=0;
    char pn[15];
    while(scanf("%s",pn)==1)
    {
        a[pp].name=pn;
        a[pp].solve=0;a[pp].time=0;
        for(int i=0;i<n;i++)
        {
            char np[100];
            scanf("%s",np);
            if(np[0]=='-'||np[0]=='0')continue;
            a[pp].solve++;
            int score=0,pt=0,p=0;
            while(np[p]!='\0'&&np[p]!='(')
            {
                score*=10;
                score+=np[p]-'0';
                p++;
            }
            if(np[p]=='(')
            {
                p++;
                while(np[p]!=')')
                {
                    pt*=10;
                    pt+=np[p]-'0';
                    p++;
                }
            }
            score+=(pt*ft);
            a[pp].time+=score;
        }
        pp++;
    }
    sort(a,a+pp,compare);
    for(int i=0;i<pp;i++)
    {
        printf("%s",a[i].name.c_str());
        for(int j=0;j<10-a[i].name.length();j++)printf(" ");
        if(a[i].solve<10)printf("  %d ",a[i].solve);
        else printf(" %d ",a[i].solve);
        if(a[i].time>999)printf("%d\n",a[i].time);
        else if(a[i].time>99)printf(" %d\n",a[i].time);
        else if(a[i].time>9)printf("  %d\n",a[i].time);
        else printf("   %d\n",a[i].time);
    }
}
