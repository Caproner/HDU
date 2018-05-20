#include<stdio.h>
int main()
{
  int a;
  while(scanf("%d",&a)==1)
  {
    if(a>89&&a<101)printf("A\n");
    else if(a>79&&a<90)printf("B\n");
    else if(a>69&&a<80)printf("C\n");
    else if(a>59&&a<70)printf("D\n");
    else if(a<101&&a>-1)printf("E\n");
    else printf("Score is error!\n");
  }
  return 0;
}
