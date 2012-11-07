#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10633
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	unsigned long long a;
	unsigned long long b;
	while(scanf("%llu",&a) && a)
	{
	      i=(a%9);
	      b=a*10;
	      b/=9;
		if(!i) printf("%llu %llu\n",b-1,b);
		else printf("%llu\n",b);
	}
	return 0;
}
