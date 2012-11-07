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

#define INF 1000000
#define VISITED 1
#define WAITING 2
#define UNVISITED 0

/*problem id-10959
 *
 *language-C++
 *
 */

using namespace std;

int min(int a,int b)
{
      return a<b ? a : b;
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
	int y,dis[1002],vis[1002];
	bool blank=false;
	vector<int> AdjList[1002];
	queue<int> q;
	scanf("%d",&t);
	while(t--)
	{
		if(blank) printf("\n"); blank=true;
		scanf("%d %d",&n,&m);
		memset(vis,0,sizeof(vis));
		for(i=1,dis[0]=0;i<n;i++) dis[i]=INF;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			AdjList[x].push_back(y);
			AdjList[y].push_back(x);
		}
		q.push(0);
		while(!q.empty())
		{
			x=q.front(); q.pop();
			for(i=0,l=AdjList[x].size();i<l;i++)
			{
				dis[AdjList[x][i]]=min(dis[AdjList[x][i]],dis[x]+1);
				if(vis[AdjList[x][i]]==UNVISITED)
				{
				      vis[AdjList[x][i]]=WAITING;
				      q.push(AdjList[x][i]);
				}
			}
			vis[x]=true;
		}
		for(i=1;i<n;i++) printf("%d\n",dis[i]);
		for(i=0;i<n;i++) AdjList[i].clear();
	}
	return 0;
}
