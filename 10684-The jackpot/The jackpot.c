#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-10684
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
	int max;
	int a[10005];
	while(scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=x=0,max=-100000000;i<n;i++)
		{
		      x+=a[i];
		      if(x<0) x=0;
			else if(x>max) max=x;
		}
		if(max>0) printf("The maximum winning streak is %d.\n",max);
		else printf("Losing streak.\n");
	}
	return 0;
}
