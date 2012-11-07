#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-696
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	while(scanf("%d %d",&m,&n) && (n || m))
	{
	      if(m==1 || n==1) x=n*m;
	      else if(n==2 || m==2)
	      {
	            y=m>n ? m : n;
	            x=(y/4)*4;
	            if(y%4) x+=(y%4)==1 ? 2 : 4;
	      }
	      else x=((m+1)/2)*((n+1)/2)+(m/2)*(n/2);
		printf("%d knights may be placed on a %d row %d column board.\n",x,m,n);
	}
	return 0;
}
