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

/*problem id-247
 *
 *language-C++
 *
 */

using namespace std;

bool vis[30];
vector<int> SCC;
vector<int> TopoSort;
vector<int> AdjList[30];
vector<int> RevAdjList[30];

void DFS(int n)
{
      if(vis[n]) return;
      vis[n]=true;
      for(int i=0;i<AdjList[n].size();i++) DFS(AdjList[n][i]);
      TopoSort.push_back(n);
      return;
}

void DFS1(int n)
{
      if(!vis[n]) return;
      vis[n]=false;
      for(int i=0;i<RevAdjList[n].size();i++) DFS1(RevAdjList[n][i]);
      SCC.push_back(n);
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
	int cnt;
	bool blank=false;
	char a[50];
	char b[50];
	char name[30][50];
	map<string,int> idx;
	map<int,set<int> > call;
	map<int,set<int> >::iterator itm;
	set<int>::iterator its; k=1;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
	      if(blank) printf("\n");
	      blank=true;
	      cnt=1;
	      idx.clear();
	      call.clear();
	      TopoSort.clear();
	      memset(vis,false,sizeof(vis));
	      for(i=1;i<=n;i++) { AdjList[i].clear(); RevAdjList[i].clear(); }
	      for(i=0;i<m;i++)
	      {
	      	scanf("%s %s",a,b);
                  if(!idx[a]) { idx[a]=cnt++; strcpy(name[cnt-1],a); }
                  if(!idx[b]) { idx[b]=cnt++; strcpy(name[cnt-1],b); }
                  call[idx[a]].insert(idx[b]);
	      }
	      for(itm=call.begin();itm!=call.end();itm++)
	      {
	      	for(its=(itm->second).begin(),x=itm->first;its!=(itm->second).end();its++)
	      	{
	      		AdjList[x].push_back(*its);
	      		RevAdjList[*its].push_back(x);
	      	}
	      }
	      printf("Calling circles for data set %d:\n",k++);
	      for(i=1;i<cnt;i++) DFS(i);
	      for(i=TopoSort.size()-1;i>=0;i--)
	      {
	      	if(vis[TopoSort[i]])
	      	{
	      	      SCC.clear();
	      	      DFS1(TopoSort[i]);
	      	      printf("%s",name[SCC[0]]);
	      	      for(j=1;j<SCC.size();j++) printf(", %s",name[SCC[j]]);
	      	      printf("\n");
	      	}
	      }
	}
	return 0;
}
