#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11723
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
	int x;
	int y;
	i=0;
	while(scanf("%d %d",&m,&n)==2 && m && n)
	{
		printf("Case %d: ",++i);
		if(n>=m) {printf("0\n");continue;}
		m-=n;
		k=m/n;
		if(m%n) k++;
		if(k>26) printf("impossible");
		else printf("%d",k);
		printf("\n");
	}
	return 0;
}
