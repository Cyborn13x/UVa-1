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
#define SZ 205

/*problem id-11450
 *
 *language-ANSI C
 *
 */

int dp[22][SZ],N,M,data[22][22];

int Solve(int n,int m)
{
      int i,x,ret=-INF;
      if(m<0) return -INF;
      if(n<0) return 0;
      if(dp[n][m]!=-1) return dp[n][m];
      for(i=1;i<=data[n][0];i++) ret=max(ret,data[n][i]+Solve(n-1,m-data[n][i]));
      return dp[n][m]=ret;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
	      clear(dp,-1);
		scanf("%d %d",&M,&N);
		for(i=0;i<N;i++)
		{
			scanf("%d",&data[i][0]);
			for(j=1;j<=data[i][0];j++) scanf("%d",&data[i][j]);
		}
		if((x=Solve(N-1,M))>0) printf("%d\n",x);
		else printf("no solution\n");
	}
	return 0;
}
