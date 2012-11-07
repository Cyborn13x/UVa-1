#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10364
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
	int x;
	int y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		x=-1000;
		y=-x;
		while(n--)
		{
			scanf("%d",&m);
			x=m>x?m:x;
			y=m<y?m:y;
		}
		n=2*(x-y);
		printf("%d\n",n);
	}
	return 0;
}
