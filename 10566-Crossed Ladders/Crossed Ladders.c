#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define ERROR 1e-8

/*problem id-10566
 *
 *language-ANSI C
 *
 */

double min(double a,double b) { return a<b ? a : b; }

double Bisection(double x,double y,double c)
{
      double low=0,high=min(x,y),mid,tmp,d,e;
      while(low<=high)
      {
      	mid=(low+high)/2;
      	d=sqrt(x*x-mid*mid);
      	e=sqrt(y*y-mid*mid);
      	tmp=(d*e)/(d+e);
      	if(tmp>c) low=mid;
      	else if((tmp>c && tmp-c<ERROR) || (tmp<c && c-tmp<ERROR)) return mid;
      	else high=mid;
      }
}

int main()
{
      double x,y,c,d,e,ab;
      while(scanf("%lf %lf %lf",&x,&y,&c)!=EOF) printf("%.3lf\n",Bisection(x,y,c));
	return 0;
}
