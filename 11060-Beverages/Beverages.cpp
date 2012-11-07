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

/*problem id-11060
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
	int ind;
	int Indeg[110];
	char a[100];
	char b[100];
	bool vis[105];
	string Input[102];
	vector<int> AdjList[101];
	map<string,int> mp;l=0;
	map<int,string> res;
	while(scanf("%d",&n)!=EOF)
	{
	      ind=0;mp.clear();
	      memset(Indeg,0,sizeof(Indeg));
	      memset(vis,false,sizeof(vis));
	      for(i=0;i<n;i++) AdjList[i].clear();
	      for(i=0;i<n;i++)
	      {
	      	scanf("%s",a);
	      	mp[a]=i;
	      	Input[i]=a;
	      }
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s %s",a,b);
			Indeg[mp[b]]++;
			AdjList[mp[a]].push_back(mp[b]);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:",++l);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n && (Indeg[j] || vis[j]);j++);
			vis[j]=true;
			cout << " " << Input[j];
			y=AdjList[j].size();
			for(k=0;k<y;k++) Indeg[AdjList[j][k]]--;
		}
		printf(".\n\n");
	}
	return 0;
}
