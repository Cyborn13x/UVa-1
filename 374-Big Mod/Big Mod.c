#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

#define sqr(x) (x*x)

/*problem id-374
 *
 *language-ANSI C
 *
 */

int BigMod(long long int b,long long int p,int m)
{
      if(p==0) return 1;
      else if(p%2==0) return (sqr(BigMod(b,p/2,m)))%m;
      else return ((b%m)*BigMod(b,p-1,m))%m;
}

int main()
{
	int i;
	int j;
	long long int b;
	long long int p;
	int m;
	while(scanf("%lld %lld %d",&b,&p,&m)==3)
	{
	      getchar();
		  printf("%d\n",BigMod(b,p,m));
	}
	return 0;
}
