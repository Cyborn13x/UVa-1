#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11388
 *
 *language-ANSI C
 *
 */

int main()
{
	int t;
	int x;
	int y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		if(y%x) printf("-1");
		else printf("%d %d",x,y);
		printf("\n");
	}
	return 0;
}
