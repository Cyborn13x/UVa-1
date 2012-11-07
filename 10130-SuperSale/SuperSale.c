#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 1002
#define ll long long int

/*problem id-10130
 *
 *language-ANSI C
 *
 */

int N,M,dp[SZ][32],price[SZ],weight[SZ],maxw;

int max(int a,int b) { return a>b ? a : b; }

int knapsack(int n,int w)
{
      int x=0,y;
      if(n==N) return 0;
      if(dp[n][w]!=-1) return dp[n][w];
      if(w+weight[n]<=maxw) x=price[n]+knapsack(n+1,w+weight[n]);
      y=knapsack(n+1,w);
      return dp[n][w]=max(x,y);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&N);
		for(i=res=0;i<N;i++) scanf("%d %d",&price[i],&weight[i]);
		scanf("%d",&m);
		while(m--)
		{
		      memset(dp,-1,sizeof(dp));
			scanf("%d",&maxw);
			res+=knapsack(0,0);
		}
		printf("%d\n",res);
	}
	return 0;
}
