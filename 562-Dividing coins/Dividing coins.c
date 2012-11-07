#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define N 25500
#define SZ 105

/*problem id-562
 *
 *language-ANSI C
 *
 */

int dp[N][SZ],a[SZ];

int max(int a,int b) { return a>b ? a : b; }

int knapsack(int w,int n)
{
      if(!n) return 0;
      if(dp[w][n]!=-1) return dp[w][n];
      return dp[w][n]=a[n-1]>w ? knapsack(w,n-1) : max(a[n-1]+knapsack(w-a[n-1],n-1),knapsack(w,n-1));
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n); sum=0;
		memset(dp,-1,N*SZ*sizeof(int));
		for(i=0;i<n;i++) { scanf("%d",&a[i]); sum+=a[i]; }
		printf("%d\n",sum-2*knapsack(sum/2,n));
	}
	return 0;
}
