#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-125
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
	int floyd[32][32]; t=0;
      while(scanf("%d",&m)!=EOF)
      {
            memset(floyd,0,sizeof(floyd));
      	for(i=0,n=-1;i<m;i++)
      	{
      		scanf("%d %d",&x,&y);
      		floyd[x][y]=1;
      		if(x>n) n=x;
      		if(y>n) n=y;
      	}
      	for(k=0;k<=n;k++)
      	{
      		for(i=0;i<=n;i++)
      		{
      			for(j=0;j<=n;j++)
      			{
      				if(floyd[i][k] && floyd[k][j])
      				{
      				      floyd[i][j] += floyd[i][k]*floyd[k][j];
      				}
      			}
      		}
      	}
      	for(k=0;k<=n;k++)
      	{
      		if(floyd[k][k])
      		{
      		      for(i=0;i<=n;i++)
      		      {
      		      	for(j=0;j<=n;j++)
      		      	{
      		      		if(floyd[i][k] && floyd[k][j])
      		      		{
      		      		      floyd[i][j]=-1;
      		      		}
      		      	}
      		      }
      		}
      	}
      	printf("matrix for city %d\n",t++);
      	for(i=0;i<=n;i++)
      	{
      		for(j=0;j<=n;j++)
      		{
      			printf("%d",floyd[i][j]);
      			if(j<n) printf(" ");
      		}
      		printf("\n");
      	}
      }
	return 0;
}
