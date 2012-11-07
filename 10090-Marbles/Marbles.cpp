#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

#define WRITE(a) freopen(a,"w",stdout)
#define READ(a) freopen(a,"r",stdin)
#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define pi 3.14159265358979323846
#define llu unsigned long long int
#define ll long long int
#define INF (2000000000000000000)
#define SZ 100000

using namespace std;

ll ExtendedEuclid(ll a,ll b,ll &x,ll &y)
{
      ll x1,y1,gcd;
      if(b==0)
      {
            x=1, y=0;
            return a;
      }
      gcd=ExtendedEuclid(b,a%b,x1,y1);
      y=x1-(a/b)*y1;
      x=y1;
      return gcd;
}

ll GCD(ll a,ll b)
{
      return a==0 ? b : GCD(b%a,a);
}

int main()
{
      //READ("in.txt");
	ll a,b,c,d,g,i,j,k,m,n,n1,n2,m1,m2,c1,c2,t,x,y,z,xo,yo,low,high;
      while(scanf("%lld",&n) && n)
      {
      	scanf("%lld %lld %lld %lld",&c1,&n1,&c2,&n2);
      	g=GCD(n1,n2);
      	if(n%g)
      	{
      	      printf("failed\n");
      	      continue;
      	}
      	n/=g, n1/=g, n2/=g;
      	m=ExtendedEuclid(n1,n2,x,y);
            x*=n, y*=n;
            low=(ll)ceil(-(double)x/n2), high=(ll)floor((double)y/n1);
            if(low>high)
      	{
      	      printf("failed\n");
      	      continue;
      	}
            a=x+n2*low, b=y-n1*low;
            c=x+n2*high, d=y-n1*high;
            if(c1*a+c2*b<=c1*c+c2*d) printf("%lld %lld\n",a,b);
            else printf("%lld %lld\n",c,d);
      }
	return 0;
}
