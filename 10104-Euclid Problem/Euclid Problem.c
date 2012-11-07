#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-10104
 *
 *language-ANSI C
 *
 */

int ExtendedEuclid(int A,int B,int *x,int *y)
{
      int x1=1,x2=0,xi,y1=0,y2=1,yi,a=A,b=B,div,rem;
      for(;b;a=b,b=rem,x1=x2,y1=y2,x2=xi,y2=yi)
      {
            div=a/b, rem=a%b;
      	xi = x1-div*x2;
      	yi = y1-div*y2;
      }
      *x=x1, *y=y1;
      return a;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		t=ExtendedEuclid(m,n,&x,&y);
		printf("%d %d %d\n",x,y,t);
	}
	return 0;
}
