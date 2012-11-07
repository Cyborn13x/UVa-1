#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define clear(x,y) memset(x,y,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 301

/*problem id-10306
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,S,blank=0,test=0,dp[SZ][SZ],a[42],b[42];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&S);
		for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
		for(i=0;i<=S;i++)
		{
			for(j=0;j<=S;j++)
			{
				dp[i][j]=INF;
			}
		}
		for(k=0,dp[0][0]=0;k<n;k++)
		{
			for(i=a[k];i<=S;i++)
			{
				for(j=b[k];j<=S;j++)
				{
					dp[i][j]=min(dp[i][j],1+dp[i-a[k]][j-b[k]]);
				}
			}
		}
		for(i=0,x=INF;i<=S;i++)
		{
			for(j=0;j<=S;j++)
			{
				if(i*i+j*j==S*S)
				{
				      x=min(x,dp[i][j]);
				}
			}
		}
		if(x==INF) printf("not possible\n");
            else printf("%d\n",x);
	}
	return 0;
}
