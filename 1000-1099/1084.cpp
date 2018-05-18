#include<cstdio>
#include<algorithm>
using namespace std;
struct person
{
    int solve;
    int h,m,s;
    int num,prize;
};
bool compare(person a,person b)
{
    if(a.solve>b.solve)return true;
    else if(a.solve==b.solve)
    {
        if(a.h<b.h)return true;
        else if(a.h==b.h)
        {
            if(a.m<b.m)return true;
            else if(a.m==b.m)return a.s<b.s;
            else return false;
        }
        else return false;
    }
    else return false;
}
bool comp(person a,person b)
{
    return a.num<b.num;
}
int main()
{
    int t;
    while(scanf("%d",&t)==1&&(t+1))
    {
        person a[105];
        int pn[6]={0};
        for(int i=0;i<t;i++)
        {
            scanf("%d %d:%d:%d",&a[i].solve,&a[i].h,&a[i].m,&a[i].s);
            a[i].num=i;
            pn[a[i].solve]++;
        }
        sort(a,a+t,compare);
        int it=0;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<pn[5-i];j++)
            {
                if(a[it].solve==5)a[it].prize=100;
                else if(a[it].solve==0)a[it].prize=50;
                else
                {
                    a[it].prize=50+a[it].solve*10;
                    if(j<pn[5-i]/2)a[it].prize+=5;
                }
                it++;
            }
        }
        sort(a,a+t,comp);
        for(int i=0;i<t;i++)
            printf("%d\n",a[i].prize);
        printf("\n");
    }
}
