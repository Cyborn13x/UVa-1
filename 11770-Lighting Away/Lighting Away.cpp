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

#define N 10001

/*problem id-11770
 *
 *language-C++
 *
 */

using namespace std;

int n;
int m;
int SCC;
int CurrPar;
int degree[N];
int component[N];
bool vis[N];
vector<int> topo;
vector<int> AdjList[N];
vector<int> RevAdjList[N];

void DFS1(int w)
{
      if(vis[w]) return;
      vis[w]=true;
      for(int i=0,l=AdjList[w].size();i<l;i++) DFS1(AdjList[w][i]);
      topo.push_back(w);
      return;
}

void DFS2(int w)
{
      if(!vis[w]) return;
      vis[w]=false; component[w]=CurrPar;
      for(int i=0,l=RevAdjList[w].size();i<l;i++) DFS2(RevAdjList[w][i]);
      return;
}

void FindSCC()
{
      int i;
      memset(vis,false,sizeof(vis));
      for(i=1;i<=n;i++) DFS1(i);
      for(i=topo.size()-1,CurrPar=0;i>=0;i--) if(vis[topo[i]]) { CurrPar++; DFS2(topo[i]); }
      for(i=1;i<=CurrPar;i++) degree[i]=0;
      for(i=1;i<=n;i++) for(int j=0,l=AdjList[i].size();j<l;j++) if(component[i]!=component[AdjList[i][j]]) degree[component[AdjList[i][j]]]=1;
      for(i=1,SCC=0;i<=CurrPar;i++) if(!degree[i]) SCC++;
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int t;
	int x;
	int y;
	scanf("%d",&t);k=1;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1,topo.clear();i<=n;i++) { AdjList[i].clear(); RevAdjList[i].clear(); }
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			AdjList[x].push_back(y);
			RevAdjList[y].push_back(x);
		}
		FindSCC();
		printf("Case %d: %d\n",k++,SCC);
	}
	return 0;
}
