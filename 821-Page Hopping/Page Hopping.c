#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-821
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,max,sum,floyd[101][101],used[101],cnt;
	double ans;
	while(scanf("%d %d",&x,&y) && (x || y))
	{
	      for(i=1;i<101;i++)
	      {
	      	for(j=1;j<101;j++)
	      	{
	      		floyd[i][j]=10000000;
	      	}floyd[i][i]=used[i]=0;
	      }
		max=0;
		floyd[x][y]=1;
		while(scanf("%d %d",&x,&y) && (x || y))
		{
			floyd[x][y]=1;
			used[x]=used[y]=1;
			if(x>max) max=x;
			if(y>max) max=y;
		}
		for(k=1,cnt=0;k<=max;k++)
		{
		      if(!used[k]) continue;
		      else cnt++;
			for(i=1;i<=max;i++)
			{
			      if(!used[i]) continue;
				for(j=1;j<=max;j++)
				{
				      if(!used[j]) continue;
					if(floyd[i][k]+floyd[k][j]<floyd[i][j])
					{
					      floyd[i][j]=floyd[i][k]+floyd[k][j];
					}
				}
			}
		}
		for(i=1,x=cnt*(cnt-1),sum=0;i<=max;i++)
		{
		      if(!used[i]) continue;
			for(j=1;j<=max;j++)
			{
			      if(!used[j]) continue;
				sum+=floyd[i][j];
			}
		}
		ans=(sum*1.0)/x;
		printf("Case %d: average length between pages = %.3lf clicks\n",++test,ans);
	}
	return 0;
}
