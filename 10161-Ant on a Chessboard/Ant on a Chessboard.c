#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-10161
 *
 *language-ANSI C
 *
 */

typedef unsigned long long int ull;

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int t;
	ull x;
	int y=0;
	ull top;
	ull cntr;
	ull row;
	ull col;
	ull n;
	ull a;
	while(scanf("%llu",&n) && n)
	{
	      x=(ull)ceil(sqrt(n));
	      top=x*x; cntr=top-x+1;
	      if(x%2==1)
	      {
	            if(n<=cntr)
	            {
	                  col=x;
	                  row=(n-(x-1)*(x-1));
	            }
	            else
	            {
	                  col=(top-n+1);
	                  row=x;
	            }
	      }
	      else
	      {
	            if(n>=cntr)
	            {
	                  col=x;
	                  row=top-n+1;
	            }
	            else
	            {
	                  col=n-(x-1)*(x-1);
	                  row=x;
	            }
	      }
		printf("%llu %llu\n",col,row);
	}
	return 0;
}
