#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 105

/*problem id-10667
 *
 *language-ANSI C
 *
 */

int max(int a,int b) { return a>b ? a : b; }

int main()
{
	int i,j,k,l,m,n,t,x,y,lim,mx,blank=0,test=0,sum[SZ][SZ],a[SZ][SZ];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		memset(a,0,SZ*SZ*sizeof(int));
		while(m--)
		{
			scanf("%d %d %d %d",&x,&y,&k,&l);
			for(i=x;i<=k;i++)
			{
				for(j=y;j<=l;j++)
				{
					a[i][j]=1;
				}
			}
		}
		for(i=1,sum[0][0]=0;i<=n;i++) sum[i][0]=sum[0][i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		}
		for(i=1,mx=0;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
                        for(k=i;k<=n;k++)
                        {
                              for(l=j;l<=n;l++)
                              {
                                    if(sum[k][l]-sum[i-1][l]-sum[k][j-1]+sum[i-1][j-1]==0) mx=max(mx,(l-j+1)*(k-i+1));
                              }
                        }
                  }
		}
		printf("%d\n",mx);
	}
	return 0;
}
