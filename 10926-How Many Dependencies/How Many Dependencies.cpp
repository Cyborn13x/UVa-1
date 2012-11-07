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

/*problem id-10926
 *
 *language-C++
 *
 */

using namespace std;

bool vis[105];
int t;
int len[105];
vector<int> v[105];

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
	int x;
	int y;
	int maxi;
	int ans;
	while(scanf("%d",&n) && n)
	{
	    memset(len,0,sizeof(len));
	    for(i=1;i<=n;i++) v[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			len[i]=m;
			for(j=0;j<m;j++)
			{
				scanf("%d",&t);
				v[i].push_back(t);
			}
		}
		maxi=-10;
		for(i=1;i<=n;i++)
		{
			memset(vis,false,sizeof(vis));
            DFS(i);
            k=0;
            for(j=1;j<=n;j++) if(vis[j]) k++;
            if(k>maxi)
            {
                maxi=k;
                ans=i;
            }
		}
		printf("%d\n",ans);
	}
	return 0;
}
