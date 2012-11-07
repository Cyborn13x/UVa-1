#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10392
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	long long int n;
	while(scanf("%lld",&n) && (n>0))
	{
		for(i=2;i<=sqrt(n);i++) for(;!(n%i);n/=i) printf("    %d\n",i);
		if(n!=1) printf("    %lld\n\n",n);
	}
	return 0;
}
