#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-825
 *
 *language-ANSI C
 *
 */

int grid[105][105];
int vis[105][105];

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
	int y=0;
	char a[10000];
	char *p;
	scanf("%d",&t);
	while(t--)
	{
	      if(y) printf("\n");
	      y=1;
		scanf("%d %d",&n,&m);
		getchar();
		memset(grid,0,sizeof(grid));
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
		{
			gets(a);
			p=strtok(a," ");
			x=atoi(p);
			p=strtok(NULL," ");
			while(p!=NULL)
			{
				y=atoi(p);
				vis[x][y]=1;
				p=strtok(NULL," ");
			}
		}
		grid[1][0]=1;
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(!vis[i][j]!=0) grid[i][j]=grid[i-1][j]+grid[i][j-1];
		printf("%d\n",grid[n][m]);
	}
	return 0;
}
