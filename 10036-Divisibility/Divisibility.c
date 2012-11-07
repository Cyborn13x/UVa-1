#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 10002
#define ll long long int

/*problem id-10036
 *
 *language-ANSI C
 *
 */

int dp[102][SZ],K,N,a[SZ];

int BackTrack(int n,int sum)
{
      sum=((sum%K)+K)%K;
      if(n==N) return !sum;
      if(dp[sum][n]!=-1) return dp[sum][n];
      return dp[sum][n]=(BackTrack(n+1,sum+a[n])|BackTrack(n+1,sum-a[n]));
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
	      memset(dp,-1,sizeof(dp));
		scanf("%d %d",&N,&K);
		for(i=0;i<N;i++) scanf("%d",&a[i]);
		printf("%s\n",BackTrack(0,0)?"Divisible":"Not divisible");
	}
	return 0;
}
