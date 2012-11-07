#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10784
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
	int x=1;
	int y;
	long long int N;
	long long int ans;
	while(scanf("%lld",&N) && N)
	{
		ans=ceil((3+sqrt(9+8*N))/2);
		printf("Case %d: %d\n",x++,ans);
	}
	return 0;
}
