#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000

/*problem id-10879
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Case #%d: %d = ",++test,n);
		for(i=2,x=0;x<2;i++)
		{
			if(n%i==0)
			{
			      if(!x) printf("%d * %d = ",i,n/i);
			      else printf("%d * %d\n",i,n/i);
			      x++;
			}
		}
	}
	return 0;
}
