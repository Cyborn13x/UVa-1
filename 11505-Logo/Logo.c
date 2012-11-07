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
#define RAD(x) (x*pi/180.0)

/*problem id-11505
 *
 *language-ANSI C
 *
 */

double pi=acos(-1);

int main()
{
	int i,j,k,l,m,n,t,blank=0,test=0;
	double x,y,z,angl;
	char a[5];
	scanf("%d",&t);
	while(t--)
	{
	      x=y=angl=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s %lf",a,&z);
			if(a[0]=='f') x+=(z*cos(angl)), y+=(z*sin(angl));
			else if(a[0]=='b') x-=(z*cos(angl)), y-=(z*sin(angl));
			else if(a[0]=='l') angl+=RAD(z);
			else if(a[0]=='r') angl-=RAD(z);
		}
		printf("%.0lf\n",sqrt(x*x+y*y));
	}
	return 0;
}
