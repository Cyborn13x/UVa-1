#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-11614
 *
 *language-ANSI C
 *
 */

typedef unsigned long long int ull;

ull last=1414213562;

ull val(ull n) { return (ull)((double)(n*1.0/2)*1.0*(n+1)); }

int BinarySearch(ull low,ull high,ull value)
{
      ull mid;
      while(low<=high)
      {
      	mid=(low+high)/2;
      	if(value>val(mid))
      	{
      	      low=mid+1;
      	      if(value<val(mid+1)) return mid;
      	}
      	else if(value==val(mid)) return mid;
      	else
      	{
      	      high=mid-1;
      	      if(value>val(mid-1)) return high;
      	}
      }
}

int main()
{
	int t;
	ull x,y;
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%llu",&x);
      	printf("%d\n",BinarySearch(1,last,x));
      }
	return 0;
}
