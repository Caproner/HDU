#include<stdio.h>
#include<math.h>
int main()
{

    double a, x1, y1, x2, y2;
    while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2)==4)
    {
    
        a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        printf("%.2lf\n", a);
    }
}
