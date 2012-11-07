#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10792
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
	int r;
	int d;
	int h1;
    double ans;
	double h2;
	double x;
	double y;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d",&r,&d,&h1);
		x=asin(((r-h1)*1.0)/r);
		y=asin(((r-d)*1.0)/r);
		ans=(2*sqrt(2*r*d-d*d))*sin(x-y);
		ans+=h1;
		printf("Case %d: %.4lf\n",i+1,ans);
	}

	return 0;
}
