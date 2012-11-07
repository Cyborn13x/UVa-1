#include <stdio.h>

#define ll long long int

/*problem id-11934
 *
 *language-ANSI C
 *
 */

ll a,b,c;

ll f(ll x) { return a*x*x+b*x+c; }

int main()
{
	ll i,l,d,x;
	while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l))
	{
		if(!a && !b && !c && !l && !d) break;
		for(i=x=0;i<=l;i++) if(f(i)%d==0) x++;
		printf("%d\n",x);
	}
	return 0;
}
