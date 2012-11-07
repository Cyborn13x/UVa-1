#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10405
 *
 *language-ANSI C
 *
 */

int MX(int a,int b){return a>b?a:b;}

int lcs[1005][1005];

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
	char s1[1005];
	char s2[1005];
	while(gets(s1) && gets(s2))
	{
		x=strlen(s1);
		y=strlen(s2);
		for(i=0;i<=x;i++) lcs[0][i]=0;
		for(i=0;i<=y;i++) lcs[i][0]=0;
		for(i=1;i<=x;i++)
		{
			for(j=1;j<=y;j++)
			{
				if(s1[i-1]==s2[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
				else lcs[i][j]=MX(lcs[i][j-1],lcs[i-1][j]);
			}
		}
		printf("%d\n",lcs[x][y]);
	}
	return 0;
}
