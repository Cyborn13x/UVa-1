#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 21

/*problem id-104
 *
 *language-ANSI C
 *
 */

int path[SZ][SZ][SZ],ans[SZ+2];
double a[SZ][SZ][SZ],tmp;

int main()
{
	int i,j,k,l,m,n,t,x,y,s,len,blank=0,test=0,dis[SZ][SZ],node;
	while(scanf("%d",&n)!=EOF)
	{
	      memset(a,0.0,SZ*SZ*SZ*sizeof(double));
		for(i=0;i<n;i++)
		{
			for(j=0,a[0][i][i]=1.0;j<n;j++)
			{
			      path[0][i][j]=i;
				if(j==i) continue;
				scanf("%lf",&a[0][i][j]);
			}
		}
		for(s=1;s<n;s++)
		{
			for(k=0;k<n;k++)
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						if((tmp=a[s-1][i][k]*a[0][k][j])>a[s][i][j])
						{
						      a[s][i][j]=tmp, path[s][i][j]=k;
						}
					}
				}
			}
		}
		for(s=1,node=-1;s<n && node==-1;s++)
		{
			for(i=0;i<n;i++)
			{
				if(a[s][i][i]>1.01)
				{
				      node=i;
                              break;
				}
			}
		}
		if(node==-1)
		{
		      printf("no arbitrage sequence exists\n");
                  continue;
		}
		for(s--,x=1,ans[0]=node,y=node;s>=0;s--)
		{
                  ans[x++]=y=path[s][node][y];
		}
		for(i=x-1;i>=1;i--) printf("%d ",ans[i]+1);
		printf("%d\n",ans[0]+1);
	}
	return 0;
}
