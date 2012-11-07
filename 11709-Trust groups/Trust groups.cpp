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

#define N 1000

/*problem id-11709
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
	char a[50];
	char b[50];
	map<string,int> ind;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
	      getchar();ind.clear();topo.clear();
	      memset(vis,false,sizeof(vis));
	      for(i=0;i<n;i++) { AdjList[i].clear(); RevAdjList[i].clear(); }
		for(i=0;i<n;i++) { gets(a); ind[a]=i; }
		for(i=0;i<m;i++)
		{
			scanf("%[^\n]%*c%[^\n]%*c",a,b);
			AdjList[ind[a]].push_back(ind[b]);
			RevAdjList[ind[b]].push_back(ind[a]);
            }
            for(i=0;i<n;i++) DFS1(i);
            for(i=topo.size()-1,k=0;i>=0;i--) if(vis[topo[i]]) { k++; DFS2(topo[i]); }
            printf("%d\n",k);
	}
	return 0;
}
