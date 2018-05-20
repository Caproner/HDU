#include<stdio.h>
int main()
{
  int i,n,a,ans;
  while(scanf("%d",&n)==1)
  {
    ans=1;
    for(i=0;i<n;i++)
    {
      scanf("%d",&a);
      if(a%2==1)ans*=a;
    }
    printf("%d\n",ans);
  }
  return 0;
}
