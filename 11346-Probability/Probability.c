#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000

/*problem id-11346
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	double a,b,s,tmp1,tmp2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf %lf",&a,&b,&s);
		if(s==0) { printf("100.000000%%\n"); continue; }
		if(4*s>=4*a*b) { printf("0.000000%%\n");  continue; }
		tmp1=s*(log(a)-log(s/b));
		tmp1+=s;
		tmp1*=4;
            tmp2=tmp1/(4*a*b);
            tmp2=1-tmp2;
            tmp2*=100;
            printf("%.6lf%%\n",tmp2);
	}
	return 0;
}
