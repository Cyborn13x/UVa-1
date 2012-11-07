#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10088
 *
 *language-ANSI C
 *
 */

long long int point[1005][2];

long long int gcd(long long int a,long long int b)
{
      return b==0 ? a : gcd(b,a%b);
}

long long int area(long long int n)
{
      long long int i;
      double a=0;
      for(i=0;i<n;i++) a+=(point[i][0]*point[(i+1)%n][1]-point[i][1]*point[(i+1)%n][0]);
      return fabs(a)/2;
}

long long int Boundary(long long int n)
{
      long long int p=0;
      long long int i;
      long long int j;
      long long int x;
      long long int y;
      for(i=0;i<n;i++)
      {
      	j=(i+1)%n;
      	if(point[i][0]==point[j][0]) p+=(long long int )abs(point[i][1]-point[j][1])-1;
      	else if(point[i][1]==point[j][1]) p+=(long long int )abs(point[i][0]-point[j][0])-1;
      	else
      	{
      	      x=(long long int )abs(point[i][1]-point[j][1]);
      	      y=(long long int )abs(point[i][0]-point[j][0]);
      	      p+=gcd(x,y)-1;
      	}
      }
      return p+n;
}

int main()
{
	long long int i;
	long long int j;
	long long int k;
	long long int l;
	long long int m;
	long long int n;
	long long int t;
	long long int x;
	long long int y;
	long long int ar;
	long long int ans;
	long long int bnd;
	while(scanf("%lld",&n) && n)
	{
		for(i=0;i<n;i++) scanf("%lld %lld",&point[i][0],&point[i][1]);
            ar=area(n);
            bnd=Boundary(n);
            ans=(ar+1-bnd/2);
            printf("%lld\n",ans);
	}
	return 0;
}
