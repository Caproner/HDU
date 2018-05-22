#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("data.in","r",stdin);
    int a,b,kk=1;
    while(scanf("%d%d",&a,&b)==2&&(a||b))
    {
        int q;
        q=(int)(sqrt((double)b*2+0.25+0.5)-0.5);
        //printf("%d\n",q);
        while(q)
        {
            double g=(double)b*2/(double)q;
            int gg=(int)g;
            if(gg-g==0)
            {
                double pp=(g-(double)(q-1))/2;
                int pq=(int)pp;
                if(pq-pp==0&&pp>0&&(gg-pq<=a))
                {
                    if(!kk)printf("\n[%d,%d]\n",pq,gg-pq);
                    else printf("[%d,%d]\n",pq,gg-pq);
                    kk++;
                }
            }
            q--;
        }
        kk=0;
    }
    printf("\n");
}
