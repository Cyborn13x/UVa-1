#include <stdio.h>

/*problem id-12459
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,n;
	long long int fib[82];
	for(i=2,fib[0]=fib[1]=1LL;i<82;i++) fib[i]=fib[i-1]+fib[i-2];
	while(scanf("%d",&n) && n) printf("%lld\n",fib[n]);
	return 0;
}
