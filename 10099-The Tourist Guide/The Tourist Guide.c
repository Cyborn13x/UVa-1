#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10099
 *
 *language-ANSI C
 *
 */

int mini(int a,int b) { return a<b ? a : b; }

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
	int S;
	int D;
	int T;
	int test=1;
	int dis[101][101];
	while(scanf("%d %d",&n,&m) && (n || m))
	{
	      for(i=1;i<=n;i++)
	      {
	      	for(j=1;j<=n;j++)
	      	{
	      		dis[i][j]=-2000000;
	      	}
	      	dis[i][i]=0;
	      }
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&t);
			dis[x][y]=dis[y][x]=t;
		}
		scanf("%d %d %d",&S,&D,&T);
		x=-10;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					dis[i][j]=maxi(dis[i][j],mini(dis[i][k],dis[k][j]));
				}
			}
		}
		T=(int)ceil((T*1.0)/(dis[S][D]-1));
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",test++,T);
	}
	return 0;
}
