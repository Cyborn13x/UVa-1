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

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 100000

/*problem id-11222
 *
 *language-C++
 *
 */

using namespace std;

struct man
{
      int id,sz;
      set<int> p,t;
      void PrintSet()
      {
            int x=0;
            set<int>::iterator it;
            printf("%d %d",id,p.size());
            for(it=p.begin();it!=p.end();it++)
            {
            	printf(" %d",*it);
            }
            printf("\n");
      }
};

bool cmp(man a,man b)
{
      return a.sz>b.sz;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	man a[3];
      scanf("%d",&t);
      set<int>::iterator it;
      while(t--)
      {
            FOR(i,3)
            {
            	a[i].id=i+1;
            	a[i].p.clear();
            	a[i].t.clear();
            }
            FOR(i,3)
            {
            	scanf("%d",&n);
            	while(n--)
            	{
            		scanf("%d",&x);
            		a[i].t.insert(x);
            	}
            }
            FOR(i,3)
            {
            	for(it=a[i].t.begin();it!=a[i].t.end();it++)
            	{
            		x=*it;
            		if(a[(i+1)%3].t.count(x) || a[(i+2)%3].t.count(x)) continue;
            		a[i].p.insert(x);
            	}
            	a[i].sz=a[i].p.size();
            }
            printf("Case #%d:\n",++test);
            sort(a,a+3,cmp);
            x=a[0].sz;
            a[0].PrintSet();
            if(x==a[1].sz) a[1].PrintSet();
            if(x==a[2].sz) a[2].PrintSet();
      }
	return 0;
}
