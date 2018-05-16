#include<bits/stdc++.h>
using namespace std;
char ch[5]=".!X#";
int mp[20][20],cg[20][20];
int tur[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int d[16];
void print()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
            printf("%c",ch[mp[i][j]]);
        printf("\n");
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<16;i++)
            scanf("%d",&d[i]);
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                scanf("%d",&mp[i][j]);
        while(n--)
        {
            for(int i=0;i<20;i++)
                for(int j=0;j<20;j++)
                {
                    cg[i][j]=mp[i][j];
                    for(int k=0;k<4;k++)
                    {
                        int x=i+tur[k][0];
                        int y=j+tur[k][1];
                        if(x<0||y<0||x>=20||y>=20)continue;
                        cg[i][j]+=mp[x][y];
                    }
                }
            for(int i=0;i<20;i++)
                for(int j=0;j<20;j++)
                {
                    mp[i][j]+=d[cg[i][j]];
                    if(mp[i][j]>3)mp[i][j]=3;
                    if(mp[i][j]<0)mp[i][j]=0;
                }
        }
        print();
        if(t)printf("\n");
    }
}