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

/*problem id-10305
 *
 *language-C++
 *
 */

using namespace std;

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
	int InDeg[105];
	int node;
	queue<int> IsolateVrtx;
	vector<int> AdjList[101];
	vector<int> TopoSort;
	while(scanf("%d %d",&n,&m))
	{
	      if(!n && !m) break;
	      for(i=0;i<100;i++) AdjList[i].clear();
	      TopoSort.clear();
		memset(InDeg,0,sizeof(InDeg));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			AdjList[x-1].push_back(y-1);
			InDeg[y-1]++;
		}
		for(i=0;i<n;i++) if(!InDeg[i]) IsolateVrtx.push(i);
		while(!IsolateVrtx.empty())
		{
			x=IsolateVrtx.front();
			IsolateVrtx.pop();
			TopoSort.push_back(x+1);
			y=AdjList[x].size();
			for(i=0;i<y;i++)
			{
				InDeg[AdjList[x][i]]--;
				if(!InDeg[AdjList[x][i]]) IsolateVrtx.push(AdjList[x][i]);
			}
		}
		printf("%d",TopoSort[0]);
		y=TopoSort.size();
		for(i=1;i<y;i++) printf(" %d",TopoSort[i]);
		printf("\n");
	}
	return 0;
}
