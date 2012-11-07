#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11152
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	double a;
	double b;
	double c;
	double s;
	double ir;
	double er;
	double ia;
	double ea;
	double ta;
	double pi=3.14159265358979323846264338327950288419716939937510;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
	{
		s=(a+b+c)/2;
		ta=sqrt(s*(s-a)*(s-b)*(s-c));
		ir=sqrt((s-a)*(s-b)*(s-c)/s);
		ia=pi*ir*ir;
		er=(a*b*c)/sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b));
		ea=pi*er*er;
		ea-=ta;
		ta-=ia;
		printf("%.4lf %.4lf %.4lf\n",ea,ta,ia);
	}
	return 0;
}
