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
#define SZ 1002

/*problem id-10310
 *
 *language-ANSI C
 *
 */

double dis(double x1,double y1,double x2,double y2)
{
      return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	int i,j,k,l,m,n,t,blank=0,test=0,esc;
	double x,y,gx,gy,dx,dy,X,Y,s1,s2;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%lf %lf %lf %lf",&gx,&gy,&dx,&dy);
		esc=0;
		while(n--)
		{
			scanf("%lf %lf",&x,&y);
			if(!esc)
			{
			      s1=2*dis(x,y,gx,gy);
			      s2=dis(x,y,dx,dy);
			      if(s1<=s2) X=x, Y=y, esc=1;
			}
		}
		if(esc) printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",X,Y);
		else printf("The gopher cannot escape.\n");
	}
	return 0;
}
