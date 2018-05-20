#include<stdio.h>
#define PI 3.1415927
int main()
{
  double a,s;
  while(scanf("%lf",&a)==1)
  {
    s=a*a*a*PI*4/3;
    printf("%.3lf\n",s);
  }
  return 0;
}
