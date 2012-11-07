#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    double n,p;
    while(scanf("%lf%lf",&n,&p)==2)
    {
          printf("%.lf\n",pow(p,1/n));
    }
    return 0;
}
