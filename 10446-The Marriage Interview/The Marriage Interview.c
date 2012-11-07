#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 100

/*problem id-10446
 *
 *language-ANSI C
 *
 */

llu dp[SZ];

llu DP(int n,int back)
{
      int i;
      llu cnt=1;
      if(n<=1) return 1;
      if(dp[n]!=-1) return dp[n];
      FORI(i,1,back) cnt+=DP(n-i,back);
      return dp[n]=cnt;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,back,blank=0,test=0;
	while(scanf("%d %d",&n,&back) && n<=60)
	{
	      SET(dp);
	      printf("Case %d: %llu\n",++test,DP(n,back));
	}
	return 0;
}
