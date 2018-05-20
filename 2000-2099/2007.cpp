#include<stdio.h>
int main()
{
  int i,m,n,a,ans1,ans2;
  while(scanf("%d %d",&m,&n)==2)
  {
    ans1=0;
    ans2=0;
    if(m>n)
    {
      m=m+n;
      n=m-n;
      m=m-n;
    }
    for(i=m;i<n+1;i++)
    {
      if(i%2==0)ans1+=(i*i);
      else ans2+=(i*i*i);
    }
    printf("%d %d\n",ans1,ans2);
  }
  return 0;
}
