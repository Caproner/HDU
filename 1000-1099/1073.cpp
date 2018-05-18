#include<bits/stdc++.h>
using namespace std;
string s[4];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        for(int ii=0;ii<4;ii++)
            s[ii].clear();
        while(true)
        {
            char c;
            c=getchar();
            s[0]+=c;
            if(c!=' '&&c!='\t'&&c!='\n')
                s[1]+=c;
            if(s[0].length()>3&&s[0][s[0].length()-1]=='D'&&s[0][s[0].length()-2]=='N'&&s[0][s[0].length()-3]=='E'&&s[0][s[0].length()-4]=='\n')break;
        }
        getchar();
        while(true)
        {
            char c;
            c=getchar();
            s[2]+=c;
            if(c!=' '&&c!='\t'&&c!='\n')
                s[3]+=c;
            if(s[2].length()>3&&s[2][s[2].length()-1]=='D'&&s[2][s[2].length()-2]=='N'&&s[2][s[2].length()-3]=='E'&&s[2][s[2].length()-4]=='\n')break;
        }
        getchar();
    //    for(int i=0;i<4;i++)
    //    {
    //        printf("-------------------------------------------------------------\n");
    //        printf("%s\n",s[i].c_str());
    //        printf("-------------------------------------------------------------\n");
    //    }
        if(s[1]!=s[3])
            printf("Wrong Answer\n");
        else if(s[0]!=s[2])
            printf("Presentation Error\n");
        else printf("Accepted\n");
    }
}
