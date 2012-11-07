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

/*problem id-280
 *
 *language-C++
 *
 */

using namespace std;

int len[105];
bool vis[105];
vector<int> AdjList[105];

void DFS(int n)
{
      if(vis[n]) return;
      vis[n]=true;
      for(int i=0;i<len[n];i++) DFS(AdjList[n][i]);
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
	int node;
	while(scanf("%d",&node) && node)
	{
	      memset(len,0,sizeof(len));
	      for(i=1;i<=node;i++) AdjList[i].clear();
		while(scanf("%d",&n) && n)
		{
			while(scanf("%d",&m) && m)
			{
				AdjList[n].push_back(m);
				len[n]++;
			}
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
		      memset(vis,false,sizeof(vis));x=0;
			scanf("%d",&n);
			for(j=0;j<len[n];j++)
			{
				DFS(AdjList[n][j]);
			}
			for(k=1;k<=node;k++) if(!vis[k]) x++;
			printf("%d",x);
			for(k=1;k<=node;k++) if(!vis[k]) printf(" %d",k);
			printf("\n");
		}
	}
	return 0;
}
