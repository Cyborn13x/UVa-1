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

/*problem id-437
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int x,y,h;
}block;

int dp[SZ],lim;
block list[SZ];

int DP(int n)
{
      int i,sum=0,k;
      if(dp[n]!=-1) return dp[n];
      FOR(i,lim)
      {
            if((list[i].x<list[n].x && list[i].y<list[n].y)||(list[i].y<list[n].x && list[i].x<list[n].y))
            {
                  k=DP(i);
                  if(k>sum) sum=k;
            }
      }
      return dp[n]=sum+list[n].h;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,res,blank=0,test=0;
	while(scanf("%d",&n) && n)
	{
	      SET(dp);
		FOR(i,n)
		{
			scanf("%d %d %d",&x,&y,&z);
			list[3*i].x=x, list[3*i].y=y, list[3*i].h=z;
			list[3*i+1].x=x, list[3*i+1].y=z, list[3*i+1].h=y;
			list[3*i+2].x=y, list[3*i+2].y=z, list[3*i+2].h=x;
		}
		res=0, lim=3*n;
		FOR(i,lim)
		{
			l=DP(i);
			if(l>res) res=l;
		}
		printf("Case %d: maximum height = %d\n",++test,res);
      }
	return 0;
}
