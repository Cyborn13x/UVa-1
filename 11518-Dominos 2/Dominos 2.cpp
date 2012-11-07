#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define N 10000

/*problem id-11518
 *
 *language-C++
 *
 */

using namespace std;

int res;
bool vis[N+2];
vector<int> AdjList[N+2];

void DFS(int x)
{
      if(vis[x]) return;
      vis[x]=true;
      res++;
      int y=AdjList[x].size();
      for(int i=0;i<y;i++) DFS(AdjList[x][i]);
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
	scanf("%d",&t);
	while(t--)
	{
	      memset(vis,false,sizeof(vis));
		scanf("%d %d %d",&n,&m,&l);
		res=0;
		for(i=0;i<n;i++) AdjList[i].clear();
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			AdjList[x-1].push_back(y-1);
		}
		for(i=0;i<l;i++)
		{
			scanf("%d",&x);
			DFS(x-1);
		}
		printf("%d\n",res);
	}
	return 0;
}
