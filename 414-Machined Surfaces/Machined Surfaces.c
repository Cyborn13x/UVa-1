#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-414
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
	int space[20];
	char a[30];
	while(scanf("%d",&n) && n)
	{
	      getchar();
	      memset(space,0,sizeof(space));x=100;
		for(i=0;i<n;i++)
		{
			scanf("%[^\n]",a);
			getchar();
			for(j=0;j<25;j++) if(a[j]==' ') space[i]++;
			x = space[i]<x ? space[i] : x ;
		}
		y=0;
		for(i=0;i<n;i++) y+=space[i]-x;
		printf("%d\n",y);
	}
	return 0;
}
