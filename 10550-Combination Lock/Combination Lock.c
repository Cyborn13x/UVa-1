#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10550
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
	int z;
	int s;
	int ans;
	while(scanf("%d %d %d %d",&s,&x,&y,&z)==4 && (s || x || y || z))
	{
		ans=1080+((s-x)<0?(s-x+40)*9:(s-x)*9)+((y-x)<0?(y-x+40)*9:(y-x)*9)+((y-z)<0?(y-z+40)*9:(y-z)*9);
		printf("%d\n",ans);
	}
	return 0;
}
