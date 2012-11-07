#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10127
 *
 *language-ANSI C
 *
 *
 */

int main()
{
	int i;
	int j;
	long int n;
	long int rem;
	long int one;
	long int div;
      while(scanf("%ld",&n)==1)
      {
      	rem=one=div=1;
      	while(rem)
      	{
      	      if(div<n)
      	      {
      	            div=div*10+1;;
      	            one++;
      	      }
      	      rem=div%n;
                  div=rem;
      	}
      	printf("%d\n",one);
      }
	return 0;
}
