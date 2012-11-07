#include <stdio.h>

/*problem id-11597
 *
 *language-ANSI C
 *
 */

int main()
{
      register int i=1;
	int n;
      while(scanf("%d",&n) && n) printf("Case %d: %d\n",i++,n/2);
	return 0;
}
