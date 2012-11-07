#include <stdio.h>

/*problem id-11044
 *
 *language-ANSI C
 *
 */

int main()
{
	int m;
	int n;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",(n/3)*(m/3));
	}
	return 0;
}
