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
#define INF 1<<30
#define SZ 100000

/*problem id-356
 *
 *language-ANSI C
 *
 */

double dis(double x,double y) { return sqrt(x*x+y*y); }

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	double r;
	while(scanf("%d",&n)!=EOF)
	{
	      if(blank) printf("\n");
	      blank=1, x=(n-1)*8+4, r=(2*n-1)/2.0;
		for(i=-n,y=0;i<n;i++)
		{
			for(j=-n;j<n;j++)
			{
                        if(dis(i,j)<=r && dis(i,j+1)<=r && dis(i+1,j)<=r && dis(i+1,j+1)<=r) y++;
			}
		}
		printf("In the case n = %d, %d cells contain segments of the circle.\n",n,x);
		printf("There are %d cells completely contained in the circle.\n",y);
	}
	return 0;
}
