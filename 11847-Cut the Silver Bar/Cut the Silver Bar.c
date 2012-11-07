#include <stdio.h>

/*problem id-11847
 *
 *language-ANSI C
 *
 */

int main()
{
	unsigned int n;
	while(scanf("%u",&n) && n) printf("%d\n",31-__builtin_clz(n));
	return 0;
}
