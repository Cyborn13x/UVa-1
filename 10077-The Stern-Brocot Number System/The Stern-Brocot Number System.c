#include <stdio.h>

/*problem id-10077
 *
 *language-ANSI C
 *
 */

void Bisection(int x,int y)
{
      int lowx=0,lowy=1,highx=1,highy=0,midx,midy;
      double a=(x*1.0)/y,b;
      midx=lowx+highx, midy=lowy+highy;
      b=(midx*1.0)/midy;
      do
      {
      	if(a<b)
      	{
      	      putchar('L');
      	      highx=midx, highy=midy;
      	}
      	else if(a>b)
      	{
      	      putchar('R');
      	      lowx=midx, lowy=midy;
      	}
      	midx=lowx+highx, midy=lowy+highy;
      	b=(midx*1.0)/midy;
      }while(a!=b);
      putchar('\n');
      return;
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n) && !(m==1 && n==1)) Bisection(m,n);
	return 0;
}
