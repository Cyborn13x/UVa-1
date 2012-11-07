#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1e9

/*problem id-423
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,floyd[102][102];
	char a[10];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1,floyd[i][i]=0;j<=n;j++)
			{
				floyd[i][j]=floyd[j][i]=INF;
			}
		}
		for(i=2;i<=n;i++)
		{
                  for(j=1;j<i;j++)
                  {
                  	scanf("%s",a);
                  	if(a[0]!='x') floyd[i][j]=floyd[j][i]=atoi(a);
                  }
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(floyd[i][k]+floyd[k][j]<floyd[i][j])
					{
					      floyd[i][j]=floyd[i][k]+floyd[k][j];
					}
				}
			}
		}
		for(i=2,m=0;i<=n;i++) if(floyd[1][i]>m) m=floyd[1][i];
		printf("%d\n",m);
	}
	return 0;
}
