#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10773
 *
 *language-ANSI C
 *
 *
 */

int main()
{
	int i;
	int j;
	int n;
	double d;
	double u;
	double v;
	double ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf %lf",&d,&v,&u);
		printf("Case %d: ",i+1);
		if(v>=u)
		{
		      printf("can't determine\n");
		      continue;
		}
		ans=d*((1.0/sqrt(u*u-v*v))-(1.0/u));
		if(!ans) printf("can't determine\n");
		else printf("%.3lf\n",ans);
	}
	return 0;
}
