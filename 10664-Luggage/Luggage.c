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
#define SZ 100000

/*problem id-10664
 *
 *language-ANSI C
 *
 */

int dp[202][22],w[22],n;

int DP(int rem,int k)
{
      if(k==n) return 0;
      if(dp[rem][k]!=-1) return dp[rem][k];
      return dp[rem][k]=(w[k]<=rem) ? max(DP(rem-w[k],k+1)+w[k],DP(rem,k+1)) : DP(rem,k+1);
}

int main()
{
	int i,j,k,l,m,t,x,y,z,blank=0,test=0;
	char a[1000],*p;
	scanf("%d%*c",&t);
	while(t--)
	{
	      SET(dp);
		gets(a);
		n=z=0, p=strtok(a," ");
		while(p!=NULL)
		{
			z+=(w[n++]=atoi(p));
			p=strtok(NULL," ");
		};
		if(z&1 || DP(z>>1,0)!=z>>1) puts("NO");
		else puts("YES");
	}
	return 0;
}
