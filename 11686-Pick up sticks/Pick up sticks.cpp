#include <iostream>
#include <sstream>
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
#define SZ 1000002

/*problem id-11686
 *
 *language-C++
 *
 */

using namespace std;

int N,M,ind[SZ];
vector<int> AdjList[SZ],TopoSort;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d %d",&N,&M) && (N || M))
	{
	      memset(ind,0,(N+1)*sizeof(int));
		for(i=1,TopoSort.clear();i<=N;i++) AdjList[i].clear();
		while(M--)
		{
			scanf("%d %d",&x,&y);
			ind[y]++;
			AdjList[x].push_back(y);
		}
		for(i=1,x=0;i<=N;i++) if(!ind[i]) { x++; TopoSort.push_back(i); }
		for(i=0,y=x;i<x;i++)
		{
		      for(j=0,k=TopoSort[i],l=AdjList[k].size();j<l;j++)
		      {
		            if(!(--ind[AdjList[k][j]]))
		            {
		                  TopoSort.push_back(AdjList[k][j]);
		                  x++;
		            }
		      }
		}
		if(x!=N) { printf("IMPOSSIBLE\n"); continue; }
		for(i=0,l=TopoSort.size();i<l;i++) printf("%d\n",TopoSort[i]);
	}
	return 0;
}
