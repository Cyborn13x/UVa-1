#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11900
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
	int p;
	int q;
	int a[50];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d",&n,&p,&q);
		for(j=0;j<n;j++) scanf("%d",&a[j]);
		m=0;
		printf("Case %d: ",i+1);
		for(j=0;j<n;j++)
		{
			if(j>=p || m+a[j]>q) break;
			m+=a[j];
		}
		printf("%d\n",j);
	}
	return 0;
}
