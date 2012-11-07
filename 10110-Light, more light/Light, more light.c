#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10110
 *
 *language-ANSI C
 *
 */

int main()
{
	long long int i;
      double n;
      while(scanf("%lf",&n) && n)
      {
      	i=(long)sqrt(n);
      	if(i*i==n) printf("yes\n");
      	else printf("no\n");
      }
	return 0;
}
