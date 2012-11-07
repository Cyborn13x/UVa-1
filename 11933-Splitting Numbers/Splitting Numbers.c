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

/*problem id-11933
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d",&n) && n)
	{
	      k=x=y=0;
		FOR(i,31)
		{
			if(n&(1<<i))
			{
			      k++;
			      if(k&1) x=x|1<<i;
			      else y=y|1<<i;
			}
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}
