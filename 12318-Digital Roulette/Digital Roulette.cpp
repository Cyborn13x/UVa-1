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
#include <algorithm>

#define Clear(x,y) memset(x,y,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 12

/*problem id-12318
 *
 *language-C++
 *
 */

using namespace std;

ll a[SZ],K,mod;

int p(int x)
{
      int i;
      ll ret=0,v=1;
      for(i=0;i<=K;i++)
      {
      	ret=(ret+((v%mod)*(a[i]%mod))%mod)%mod;
      	v=(v*(x%mod))%mod;
      }
      return ret;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	set<ll> ans;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
            ans.clear(); mod=(ll)(n+1);
		scanf("%lld",&K);
		for(i=0;i<=K;i++) scanf("%lld",&a[i]);
		for(i=0;i<=m;i++) ans.insert(p(i)%mod);
		printf("%d\n",(int)ans.size());
	}
	return 0;
}
