#include<bits/stdc++.h>
using namespace std;
int tur[4][2]={{10,0},{0,10},{-10,0},{0,-10}};
int main()
{
    char s[1005];
    while(scanf("%s",s)==1)
    {
        int p=0,len=strlen(s);
        int x=310,y=420;
        printf("300 420 moveto\n310 420 lineto\n");
        for(int i=0;i<len;i++)
        {
            if(s[i]=='V')p++;
            else p--;
            p=(p+4)%4;
            x+=tur[p][0];
            y+=tur[p][1];
            printf("%d %d lineto\n",x,y);
        }
        printf("stroke\nshowpage\n");
    }
}
