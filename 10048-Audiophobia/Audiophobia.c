#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INF 20000000

/*problem id-10048
 *
 *language-ANSI C
 *
 */

int mini(int a,int b) { return a<b ? a : b; }

int maxi(int a,int b) { return a>b ? a : b; }

int main()
{
	int i,j,k,l,m,n,t,x,y,C,S,Q,blank=0,adj[101][101];
	t=1;
	while(scanf("%d %d %d",&C,&S,&Q) && (C || S || Q))
	{
	      if(blank) printf("\n");
	      blank=1;
		for(i=1;i<=C;i++)
		{
			for(j=1;j<=C;j++)
			{
				adj[i][j]=INF;
			}
			adj[i][i]=0;
		}
		for(i=0;i<S;i++)
		{
			scanf("%d %d %d",&x,&y,&l);
			adj[x][y]=adj[y][x]=l;
		}
		for(k=1;k<=C;k++)
		{
			for(i=1;i<=C;i++)
			{
				for(j=1;j<=C;j++)
				{
					adj[i][j] = mini(adj[i][j],maxi(adj[i][k],adj[k][j]));
				}
			}
		}
		printf("Case #%d\n",t++);
		for(i=0;i<Q;i++)
		{
			scanf("%d %d",&x,&y);
			if(adj[x][y]==INF) printf("no path\n");
			else printf("%d\n",adj[x][y]);
		}
	}
	return 0;
}
