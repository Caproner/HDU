#include<stdio.h>
int main()
{
  int y,m,d,r,a[12]={31,28,31,30,31,30,31,31,30,31,30,31},i,ans;
  while(scanf("%d/%d/%d",&y,&m,&d)==3)
  {
    ans=0;
    if(y%4==0)
    {
      if(y%400==0)r=1;
      else if(y%100==0)r=0;
      else r=1;
    }
    else r=0;
    for(i=0;i<m-1;i++)ans+=a[i];
    ans+=d;
    if(m>2)ans+=r;
    printf("%d\n",ans);
  }
  return 0;
}
