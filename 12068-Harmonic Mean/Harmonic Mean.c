#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-12068
 *
 *language-ANSI C
 *
 */

long long int GCD(long int a,long int b)
{
      long long int c=1;
      while(c)
      {
      	c=a%b;
      	a=b;
      	b=c;
      }
      return a;
}

int main()
{
	int i;
	int j;
	long long int k;
	int l;
	long long int m;
	int n;
	int t;
	int x;
	long long int y;
	long long int a[12];
	scanf("%d",&t);l=1;
	while(t--)
	{
		scanf("%d",&n);m=1;y=0;
		for(i=0;i<n;i++) {scanf("%lld",&a[i]);m*=a[i];}
		for(i=0;i<n;i++) y+=(m/a[i]);
		m*=n;k=GCD(m,y);m/=k;y/=k;
		printf("Case %d: %lld/%lld\n",l++,m,y);
	}
	return 0;
}
