#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10066
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
	int a[102];
	int b[102];k=1;
	int lcs[102][102];
	while(scanf("%d %d",&n,&m) && (n || m))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<m;i++) scanf("%d",&b[i]);
		memset(lcs,0,sizeof(lcs));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i-1]==b[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
				else lcs[i][j] = maxi(lcs[i-1][j],lcs[i][j-1]);
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",k++,lcs[n][m]);
	}
	return 0;
}
