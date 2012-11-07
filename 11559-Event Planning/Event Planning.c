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

/*problem id-11559
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,p,N,B,H,W,res,blank=0,test=0;
	while(scanf("%d %d %d %d",&N,&B,&H,&W)!=EOF)
	{
	      res=INF;
		while(H--)
		{
			scanf("%d",&p);
			For(i,W)
			{
				scanf("%d",&x);
				if(x>=N && N*p<=B) res=min(res,N*p);
			}
		}
		if(res<INF) printf("%d\n",res);
		else printf("stay home\n");
	}
	return 0;
}
