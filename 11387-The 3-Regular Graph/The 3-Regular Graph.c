#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11387
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
	while(scanf("%d",&n) && n)
	{
		if(n<4 || n&1) printf("Impossible\n");
		else
		{
		      x=n*3/2;
		      printf("%d\n",x);
		      for(i=1;i<n;i++) printf("%d %d\n",i,i+1);
		      printf("%d 1\n",n);
		      l=n/2;
		      for(i=1;i<=l;i++) printf("%d %d\n",i,l+i);
		}

	}
	return 0;
}
