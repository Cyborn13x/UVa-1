#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 3002
#define ll long long int

/*problem id-10014
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	double a,b,res,c,tmp;
      scanf("%d",&t);
      while(t--)
      {
            if(blank) putchar('\n'); blank=1;
      	scanf("%d",&n);
      	scanf("%lf %lf",&a,&b);
      	for(i=tmp=0;i<n;i++) { scanf("%lf",&c); tmp+=(n-i)*c; }
      	printf("%.2lf\n",(n*a+b-tmp*2)/(n+1));
      }
	return 0;
}
