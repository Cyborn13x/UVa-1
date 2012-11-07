#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-160
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
	int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
	int power[105];
	double div;
	while(scanf("%d",&n) && n)
	{
		memset(power,0,sizeof(power));
		y=0;
		while(pr[y]<=n)
		{
			x=pr[y];
			div=(n*1.0)/x;
			while(div>=1.0)
			{
                        power[pr[y]]+=(int)div;
                        x*=pr[y];
                        div=n/x;
			}
			y++;
		}
		while(power[pr[y]]==0) y--;
		printf("%3d! =",n);
		for(i=0;i<=y;i++)
		{
		      if(i==15) printf("\n%6c",' ');
		      printf("%3d",power[pr[i]]);

		}
		printf("\n");
	}
	return 0;
}
