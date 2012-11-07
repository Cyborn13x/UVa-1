#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11526
 *
 *language-ANSI C
 *
 */

long long H(int n)
{
    int i;
    int s=sqrt(n);
    long long res=0;
    for(i=1;i<=s;i++) res+=n/i;
    return (2*res-(s*s));
}

int main()
{
	int n;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",H(n));
	}
	return 0;
}
