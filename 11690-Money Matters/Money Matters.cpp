#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-11690
 *
 *language-C++
 *
 */

using namespace std;

int f;
int fs;
int deb;
int credit[10000];
bool vis[10000];
vector<int> v[10000];

void DFS(int p)
{
      if(vis[p]) return;
      deb+=credit[p];
      vis[p]=true;
      int l=v[p].size();
      for(int i=0;i<l;i++) DFS(v[p][i]);
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
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&f,&fs);
		memset(vis,false,sizeof(vis));
		for(i=0;i<f;i++) v[i].clear();
		for(i=0;i<f;i++) scanf("%d",&credit[i]);
		for(i=0;i<fs;i++)
		{
			scanf("%d %d",&m,&n);
			v[m].push_back(n);
			v[n].push_back(m);
		}
		flag=true;
		for(i=0;i<f;i++)
		{
			deb=0;
			DFS(i);
			if(deb)
			{
			      flag=false;
			      printf("IMPOSSIBLE\n");
			      break;
			}
		}
		if(flag) printf("POSSIBLE\n");
	}
	return 0;
}
