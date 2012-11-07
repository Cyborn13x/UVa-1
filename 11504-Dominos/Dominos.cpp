#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
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

#define S 100001

/*problem id-11504
 *
 *language-C++
 *
 */

using namespace std;

int N,M,SCC,CurrPar,component[S],degree[S];
bool vis[S];
vector<int> AdjList[S],rAdjList[S],topo;

void DFS_VISIT1(int w)
{
      if(vis[w]) return;
      vis[w]=true;
      for(int i=0,l=AdjList[w].size();i<l;i++) DFS_VISIT1(AdjList[w][i]);
      topo.push_back(w);
      return;
}

void DFS_VISIT2(int w)
{
      if(!vis[w]) return;
      vis[w]=false;
      component[w]=CurrPar;
      for(int i=0,l=rAdjList[w].size();i<l;i++) DFS_VISIT2(rAdjList[w][i]);
      return;
}

void FindSCC()
{
      int i;
      memset(degree,0,sizeof(degree));
      memset(vis,false,sizeof(vis));
      for(i=1;i<=N;i++) if(!vis[i]) DFS_VISIT1(i);
      for(i=topo.size()-1,CurrPar=0;i>=0;i--) if(vis[topo[i]]) { CurrPar++; DFS_VISIT2(topo[i]); }
      for(i=1;i<=N;i++) for(int j=0,l=AdjList[i].size();j<l;j++) if(component[i]!=component[AdjList[i][j]]) degree[component[AdjList[i][j]]]=1;
      for(i=1,SCC=0;i<=CurrPar;i++) if(!degree[i]) SCC++;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y;
	scanf("%d",&t);
      while(t--)
      {
      	scanf("%d %d",&N,&M);topo.clear();
      	for(i=1;i<=N;i++) { AdjList[i].clear(); rAdjList[i].clear(); }
      	while(M--)
      	{
      		scanf("%d %d",&x,&y);
      		AdjList[x].push_back(y);
      		rAdjList[y].push_back(x);
      	}
      	FindSCC();
      	printf("%d\n",SCC);
      }
	return 0;
}
