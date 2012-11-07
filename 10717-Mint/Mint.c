#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<28
#define SZ 100000

/*problemid-10717
 *
 *language-ANSI C
 *
 */

int gcd(int a,int b)
{
      return !b ? a : gcd(b,a%b);
}

int lcm(int a,int b)
{
      return a*b/gcd(a,b);
}

int main()
{
	int i,j,k,l,m,n,mx,mn,t,x,y,blank=0,test=0,a[52];
	while(scanf("%d %d",&n,&m) && (n||m))
	{
		For(i,n) scanf("%d",&a[i]);
		while(m--)
		{
			scanf("%d",&x);
			mx=-INF, mn=INF;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					for(k=j+1;k<n;k++)
					{
						for(l=k+1;l<n;l++)
						{
							y=lcm(lcm(a[i],a[j]),lcm(a[k],a[l]));
							mx=max(mx,(x/y)*y);
							mn=min(mn,(x/y+(x%y==0?0:1))*y);
						}
					}
				}
			}
			printf("%d %d\n",mx,mn);
		}
	}
	return 0;
}
