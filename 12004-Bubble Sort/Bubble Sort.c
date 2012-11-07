#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-12004
 *
 *language-ANSI C
 *
 */

unsigned long long int GCD(unsigned long long int a,unsigned long long int b)
{
      unsigned long long int c=1;
      while(b)
      {
      	c=a%b;
      	a=b;b=c;
      }
      return a;
}

int main()
{
	register int i;
	unsigned long long int n;
	int t;
	unsigned long long int x;
	unsigned long long int y;
	unsigned long long int z;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%llu",&n);
		x=n*(n-1);y=GCD(x,4);
		printf("Case %d: ",i);
		if(4%y==0) z=4/y;
		if(z==1) printf("%llu\n",x/y);
		else printf("%llu/%llu\n",x/y,4/y);
	}
	return 0;
}
