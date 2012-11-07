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
#define SZ 32
#define N 1005

/*problem id-990
 *
 *language-ANSI C
 *
 */

int used[SZ][N],dp[SZ][N],d[SZ],p[SZ];

int Knapsack(int n,int w)
{
      int x,y;
      if(n<0 || !w) return 0;
      if(dp[n][w]!=-1) return dp[n][w];
      x=Knapsack(n-1,w);
      y=((w>=d[n]) ? (p[n]+Knapsack(n-1,w-d[n])):0);
      used[n][w]=(y>x);
      return dp[n][w]=((x>y)?x:y);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,w,blank=0,test=0,mark[SZ];
      while(scanf("%d %d",&t,&w)!=EOF)
      {
            if(blank) printf("\n");
            blank=1;
            scanf("%d",&n);
            clear(dp,-1);
            clear(used,0);
            clear(mark,0);
      	for(i=0;i<n;i++)
      	{
      	      scanf("%d %d",&d[i],&p[i]);
      	      d[i]=3*w*d[i];
      	}
      	x=Knapsack(n-1,t);
      	printf("%d\n",x);
      	x=0,i=n-1,j=t;
      	while(i>=0)
      	{
      		if(used[i][j])
      		{
      		      x++;
      		      mark[i]=1;
      		      j-=d[i];
      		}
      		i--;
      	}
      	printf("%d\n",x);
      	for(i=0;i<n;i++) if(mark[i]) printf("%d %d\n",d[i]/3/w,p[i]);
      }
	return 0;
}
