#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-12036
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int m;
	int n;
	int t;
	int f;
	int a[110];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);f=1;
		memset(a,0,sizeof(a));
		for(j=0;j<n;j++) for(k=0;k<n;k++) {scanf("%d",&m);a[m]++;if(a[m]>n) f=0;}
		printf("Case %d: %s\n",i+1,f ? "yes":"no");
	}
	return 0;
}
