#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 1001

/*problem id-10487
 *
 *language-ANSI C
 *
 */

int abs(int x) { return x<0 ? -x : x; }

int main()
{
	int i,j,k,l,m,n,t,x,y,res,blank=0,test=0,a[SZ];
	while(scanf("%d",&n) && n)
	{
		For(i,n) scanf("%d",&a[i]);
		scanf("%d",&m);
		printf("Case %d:\n",++test);
		while(m--)
		{
			scanf("%d",&t);
			res=INF;
			For(i,n)
			{
				for(j=i+1;j<n;j++)
				{
					if(abs(a[i]+a[j]-t)<res)
					{
					      res=abs(a[i]+a[j]-t);
					      x=a[i], y=a[j];
					}
				}
			}
			printf("Closest sum to %d is %d.\n",t,x+y);
		}
	}
	return 0;
}
