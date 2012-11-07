#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

typedef long long int ull;

ull ExtendedEuclid(ull A,ull B,ull *x,ull *y)
{
      ull x1=1,x2=0,xi,y1=0,y2=1,yi,a=A,b=B,div,rem;
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
	ull i,j,k,l,m,n,t,x,y,g,blank=0,test=0;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&m,&n);
		if(m%n==0) printf("%lld 0\n",n);
		else
		{
		      i=floor((double)m/n);
		      j=ceil((double)m/n);
		      g=ExtendedEuclid(i,j,&x,&y);
		      printf("%lld %lld\n",x*m,y*m);
		}
	}
	return 0;
}
