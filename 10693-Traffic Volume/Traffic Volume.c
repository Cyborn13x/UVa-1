#include <stdio.h>
#include <math.h>

/*problem id-10693
 *
 *language-ANSI C
 *
 */

int main()
{
	int L;
	int f;
	double v;
	double vol;
	while(scanf("%d %d",&L,&f) && (L || f))
	{
		v=sqrt(2.0*L*f);
		vol=(v*3600)/(2.0*L);
		printf("%.8lf %.8lf\n",v,vol);
	}

	return 0;
}
