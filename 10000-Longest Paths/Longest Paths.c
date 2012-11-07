#include <stdio.h>

/*problem id-10000
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,max,finish,blank=0,test=0,start,N,floyd[101][101];
	while(scanf("%d",&N) && N)
	{
		scanf("%d",&start);
		for(i=1,max=0;i<=N;i++) for(j=i+1,floyd[i][i]=0;j<=N;j++) floyd[i][j]=floyd[j][i]=-100000;
		while(scanf("%d %d",&x,&y) && (x || y)) floyd[x][y]=1;
		for(k=1;k<=N;k++)
		{
			for(i=1;i<=N;i++)
			{
				for(j=1;j<=N;j++)
				{
					if(floyd[i][k]+floyd[k][j]>floyd[i][j])
					{
					      floyd[i][j]=floyd[i][k]+floyd[k][j];
					}
				}
			}
		}
		for(i=N;i>0;i--)
		{
			if(floyd[start][i]>max) max=floyd[start][i], finish=i;
			else if(floyd[start][i]==max) finish=i;
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++test,start,max,finish);
	}
	return 0;
}
