#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-1185
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
	double x;
	int y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		x=0;
		for(i=1;i<=n;i++) x+=log10(i);
		x=floor(x);
		printf("%.0lf\n",x+1);
	}
	return 0;
}
