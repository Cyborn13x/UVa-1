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

#define INF 1<<30
#define SZ 52
#define ll long long int

/*problem id-11348
 *
 *language-ANSI C
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,f[10005],p[SZ];
	set<int> data[SZ];
	set<int>::iterator it;
	scanf("%d",&t);
	while(t--)
	{
	      memset(f,0,sizeof(f));
            memset(p,0,sizeof(p));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			data[i].clear();
			for(j=0;j<x;j++)
			{
			      scanf("%d",&y);
			      data[i].insert(y);
                  }
		}
		for(i=0;i<n;i++)
		{
			for(it=data[i].begin();it!=data[i].end();it++)
			{
				f[*it]++;
			}
		}
		for(i=l=0;i<n;i++)
		{
			for(it=data[i].begin();it!=data[i].end();it++)
			{
                        if(f[*it]==1) p[i]++;
			}
			l+=p[i];
		}
		printf("Case %d:",++test);
		for(i=0;i<n;i++) printf(" %.6lf%%",l==0 ? 0.00:100.0*((p[i]*1.0)/l));
		printf("\n");
	}
	return 0;
}
