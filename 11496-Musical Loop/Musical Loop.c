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
#define SZ 10002

/*problem id-11496
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,a[SZ];
	while(scanf("%d",&n) && n)
	{
	      x=0;
		FOR(i,n) scanf("%d",&a[i]);
		FORI(i,1,n-2)
		{
			if(a[i]>a[i+1] && a[i]>a[i-1]) x++;
			else if(a[i]<a[i+1] && a[i]<a[i-1]) x++;
		}
		if(a[0]>a[n-1] && a[0]>a[1]) x++;
            else if(a[0]<a[n-1] && a[0]<a[1]) x++;
            if(a[n-1]>a[n-2] && a[n-1]>a[0]) x++;
            else if(a[n-1]<a[n-2] && a[n-1]<a[0]) x++;
            printf("%d\n",x);
	}
	return 0;
}
