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

#define N 2001

/*problem id-11838
 *
 *language-C++
 *
 */

using namespace std;

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
      vis[w]=false;
      for(int i=0,l=RevAdjList[w].size();i<l;i++) DFS2(RevAdjList[w][i]);
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
      while(scanf("%d %d",&n,&m) && (n || m))
      {
            memset(vis,false,sizeof(vis)); topo.clear();
            for(i=1;i<=n;i++) { AdjList[i].clear(); RevAdjList[i].clear(); }
      	for(i=0;i<m;i++)
      	{
      		scanf("%d %d %d",&x,&y,&t);
      		AdjList[x].push_back(y);
      		RevAdjList[y].push_back(x);
      		if(t==2) { AdjList[y].push_back(x); RevAdjList[x].push_back(y); }
      	}
      	for(i=1;i<=n;i++) DFS1(i);
      	for(i=topo.size()-1,k=0;i>=0;i--) if(vis[topo[i]]) { k++; DFS2(topo[i]); }
      	if(k==1) printf("1\n");
      	else printf("0\n");
      }
	return 0;
}
