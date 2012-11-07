#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-111
 *
 *language-ANSI C
 *
 */

int maxi(int a,int b) { return a>b ? a : b; }

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
	int a[25];
	int b[25];
	int lcs[25][25];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	      scanf("%d",&x);
		a[x-1]=i;
	}
	while(scanf("%d",&m)!=EOF)
	{
		b[m-1]=1;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			b[x-1]=i;
		}
		for(i=0;i<=n;i++) lcs[0][i]=lcs[i][0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i-1]==b[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
				else lcs[i][j]=maxi(lcs[i-1][j],lcs[i][j-1]);
			}
		}
		printf("%d\n",lcs[n][n]);
	}
	return 0;
}
