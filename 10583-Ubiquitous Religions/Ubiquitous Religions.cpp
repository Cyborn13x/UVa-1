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
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

#define N 50000

/*problem id-10583
 *
 *language-C++
 *
 */

using namespace std;

bool vis[N+5];
int len[N+5];
vector<int> v[N+2];

void DFS(int x)
{
    if(vis[x]) return;
    vis[x]=true;
    for(int i=0;i<len[x];i++) DFS(v[x][i]);
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
	k=1;
	while(scanf("%d %d",&n,&m)==2)
	{
		if(!n && !m) break;
		for(i=1;i<=n;i++) v[i].clear();
		memset(len,0,sizeof(len));
		memset(vis,false,sizeof(vis));
		t=0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			v[x].push_back(y);len[x]++;
			v[y].push_back(x);len[y]++;
		}
		for(i=1;i<=n;i++)
		{
			if(!vis[i])
			{
			    t++;
			    DFS(i);
			}
		}
		printf("Case %d: %d\n",k++,t);
	}
	return 0;
}
