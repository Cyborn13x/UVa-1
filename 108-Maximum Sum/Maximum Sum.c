#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-108
 *
 *language-ANSI C
 *
 */

int a[102][102];
int s[102][102];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x=-100000000;
	int y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) s[i][j]+=a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=i;k<=n;k++)
			{
				for(l=j;l<=n;l++)
				{
					y=s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1];
					if(y>x) x=y;
				}
			}
		}
	}
	printf("%d\n",x);
      return 0;
}
