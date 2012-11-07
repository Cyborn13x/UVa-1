#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 31700

/*problem id-11970
 *
 *language-ANSI C
 *
 */

int isInt(double x) { return (int)x==x; }

int main()
{
	int i,j,k,l,m,n,t,y,blank=0,test=0,a[SZ],X,ans[SZ];
	for(i=1;i<SZ;i++) a[i]=i*i;
	scanf("%d",&t);
	while(t--)
	{
	      scanf("%d",&n);
	      printf("Case %d:",++test);
		for(i=1,j=0;(X=(n-a[i]))>0;i++) if(X%i==0) ans[j++]=X;
		for(i=j-1;i>=0;i--) printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
