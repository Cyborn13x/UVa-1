#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 1205

/*problem id-11151
 *
 *language-ANSI C
 *
 */

int dp[SZ][SZ];
char a[SZ];

int max(int a,int b) { return a>b ? a : b; }

int DP(int x,int y)
{
      if(x>y) return 0;
      if(dp[x][y]) return dp[x][y];
      if(x==y) return dp[x][y]=1;
      if(a[x-1]==a[y-1]) return dp[x][y]=2+DP(x+1,y-1);
      return dp[x][y]=max(DP(x+1,y),DP(x,y-1));
}

int main()
{
	int n;
	gets(a);
	sscanf(a,"%d",&n);
	while(n--)
	{
	      memset(dp,0,SZ*SZ*sizeof(int));
		gets(a);
		printf("%d\n",DP(1,strlen(a)));
	}
	return 0;
}
