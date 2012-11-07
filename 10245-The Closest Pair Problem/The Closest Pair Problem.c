#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10245
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	double k;
	double l;
	int m;
	int n;
	int t;
	double x[10000];
	double y[10000];
	while(scanf("%d",&n) && n)
	{
	      l=1000000000;
		for(i=0;i<n;i++) scanf("%lf %lf",&x[i],&y[i]);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				k=((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]));
				if(k<l) l=k;
			}
		}
		l=sqrt(l);
		if(l>=10000) printf("INFINITY\n");
		else printf("%.4lf\n",l);
	}

	return 0;
}
