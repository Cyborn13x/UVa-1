#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11463
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
	int start;
	int end;
	int num;
	int dis[100][100];
	scanf("%d",&t);num=1;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dis[i][j]=20000000;
			}
			dis[i][i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			dis[x][y]=dis[y][x]=1;
		}
		scanf("%d %d",&start,&end);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(dis[i][k]+dis[k][j]<dis[i][j])
					{
					      dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		l=0;
		for(i=0;i<n;i++) if(dis[start][i]+dis[i][end]>l) l=dis[start][i]+dis[i][end];
		printf("Case %d: %d\n",num++,l);
	}
	return 0;
}
