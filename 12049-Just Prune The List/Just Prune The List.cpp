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
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-x):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 100000

/*problem id-12049
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	map<int,int> f;
	map<int,int>::iterator it;
	scanf("%d",&t);
	while(t--)
	{
	      f.clear();
		scanf("%d %d",&n,&m);
		For(i,n)
		{
			scanf("%d",&x);
			f[x]++;
		}
		For(i,m)
		{
			scanf("%d",&x);
			f[x]--;
		}
		for(x=0,it=f.begin();it!=f.end();it++) x+=abs(it->second);
		printf("%d\n",x);
	}
	return 0;
}
