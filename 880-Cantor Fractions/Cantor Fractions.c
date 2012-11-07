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
#define SZ 50000000

/*problem id-880
 *
 *language-ANSI C
 *
 */

void Solve(llu n)
{
      llu x,s;
      x=(llu)(ceil((-1+sqrt(1+4*2*n))/(double)2.0));
      s=(llu)((llu)(x*x+x)/(double)2.0);
      printf("%llu/%llu\n",s-n+1,x-(s-n));
      return;
}

int main()
{
	llu n;
	while(scanf("%llu",&n)!=EOF) Solve(n);
	return 0;
}
