#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10116
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
	int row;
	int col;
	int timer;
	int loop;
	int vis[12][12];
	int time[12][12];
	char grid[12][12];
      while(scanf("%d %d %d\n",&m,&n,&x) && (m || n || x))
      {
      	timer=loop=0;row=1;col=x;
      	memset(vis,0,sizeof(vis));
      	for(i=1;i<=m;i++)
      	{
      		for(j=1;j<=n;j++)
      		{
      			scanf("%c",&grid[i][j]);
      		}
      		getchar();
      	}
      	while(row>0 && row<=m && col>0 && col<=n)
      	{
      		if(!vis[row][col])
      		{
      		      vis[row][col]=1;
      		      time[row][col]=++timer;
      		      if(grid[row][col]=='E') col++;
      		      else if(grid[row][col]=='W') col--;
      		      else if(grid[row][col]=='N') row--;
      		      else row++;
      		}
      		else
      		{
      		      printf("%d step(s) before a loop of %d step(s)\n",time[row][col]-1,timer-time[row][col]+1);
      		      loop=1;break;
                  }
      	}
      	if(!loop) printf("%d step(s) to exit\n",timer);
      }
	return 0;
}
