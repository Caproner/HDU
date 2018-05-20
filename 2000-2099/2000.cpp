#include<stdio.h>
int main()
{
  char a[3],t;
  while(1)
  {    
    a[0]=getchar();
    if(a[0]==-1)break;
    a[1]=getchar();
    if(a[0]>a[1])
    {
      t=a[0];
      a[0]=a[1];
      a[1]=t;
    }
    a[2]=getchar();
    if(a[2]<a[0])printf("%c %c %c\n",a[2],a[0],a[1]);
    else if(a[2]<a[1])printf("%c %c %c\n",a[0],a[2],a[1]);
    else printf("%c %c %c\n",a[0],a[1],a[2]);
    a[0]=getchar();
  }
  return 0;
}
