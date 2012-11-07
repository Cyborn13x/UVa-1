#include <stdio.h>

/*problem id-847
 *
 *language-ANSI C
 *
 */

int main()
{
	int x;
	int y;
	long long int n;
	long long int p;
	while(scanf("%lld",&n)!=EOF)
	{
		p=1;x=1;y=0;
		while(p<n)
		{
			if(x) { p*=9;x=0;y=1; }
 			else { p*=2;x=1;y=0; }
		}
		printf("%s wins.\n", !x ? "Stan" : "Ollie" );
	}
	return 0;
}
