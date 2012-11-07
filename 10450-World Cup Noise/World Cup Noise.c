#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define ll long long int

/*problem id-10450
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	ll fib[55];
	for(i=2,fib[0]=fib[1]=1L;i<53;i++) fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n%lld\n\n",++test,fib[n+1]);
	}
	return 0;
}

