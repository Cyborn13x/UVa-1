#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11646
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
	int y;
	double a;
	double b;
	double x;y=1;
	while(scanf("%lf : %lf",&a,&b)!=EOF)
	{
		x=200/(a+atan(b/a)*sqrt(a*a+b*b));
		printf("Case %d: %.10lf %.10lf\n",y++,x*a,x*b);
	}
	return 0;
}
