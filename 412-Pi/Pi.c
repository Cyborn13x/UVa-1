#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-412
 *
 *language-ANSI C
 *
 */

int nc2[52];

int gcd(int a,int b)
{
      if(!b) return a;
      return gcd(b,a%b);
}

int main()
{
	register int i;
	register int j;
	int n;
	int x;
	int a[52];
	double ans;
	for(i=2;i<=50;i++) nc2[i]=nc2[i-1]+i-1;
	while(scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=x=0;i<n;i++) for(j=i+1;j<n;j++) if(gcd(a[i],a[j])==1) x++;
		if(!x) printf("No estimate for this data set.\n");
		else
		{
		      ans=sqrt((6.0*nc2[n])/x);
		      printf("%.6lf\n",ans);
		}
	}
	return 0;
}
