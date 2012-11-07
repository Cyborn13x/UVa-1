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
#define INF 10000000
#define WHITE 0
#define GREY 1
#define BLACK 2

/*problem id-762
 *
 *language-C++
 *
 */

using namespace std;

int vis[N];
int dis[N];
int parent[N];
char name[N][5];
map<string,int> idx;
vector<int> AdjList[N];

int BFS(int start,int end)
{
      int i;
      int j;
      int l;
      int x;
      int y;
      queue<int> BFSque;
      memset(vis,0,N*sizeof(vis[0]));
      for(i=1;i<N;i++) dis[i]=INF;
      BFSque.push(start); vis[start]=GREY;
      dis[start]=0; parent[start]=start;
      while(!BFSque.empty() && vis[end]==WHITE)
      {
      	x=BFSque.front(); BFSque.pop();
      	for(i=0,l=AdjList[x].size();i<l;i++)
      	{
      		y=AdjList[x][i];
      		if(vis[y]==WHITE)
      		{
      		      vis[y]=GREY;
      		      dis[y]=dis[x]+1;
      		      parent[y]=x;
      		      BFSque.push(y);
      		}
      	}
      	vis[x]=BLACK;
      }
      return dis[end];
}

void PrintPath(int end)
{
      int i;
      int j;
      vector<int> path;
      while(parent[end]!=end)
      {
      	path.push_back(end);
      	end=parent[end];
      }
      path.push_back(end);
      for(i=path.size()-1;i>0;i--) printf("%s %s\n",name[path[i]],name[path[i-1]]);
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
	int ans;
	char a[5];
	char b[5];
      bool blank=false;
      while(scanf("%d",&m)!=EOF)
      {
            if(blank) printf("\n"); blank=true;
      	for(i=cnt=1,idx.clear();i<1000;i++) AdjList[i].clear();
      	for(i=0;i<m;i++)
      	{
      		scanf("%s %s",a,b);
      		if(!idx[a]) { strcpy(name[cnt],a); idx[a]=cnt++; }
      		if(!idx[b]) { strcpy(name[cnt],b); idx[b]=cnt++; }
      		AdjList[idx[a]].push_back(idx[b]);
      		AdjList[idx[b]].push_back(idx[a]);
      	}
      	scanf("%s %s",a,b);
      	if(!idx[a] || !idx[b]) { printf("No route\n"); continue; }
      	ans=BFS(idx[a],idx[b]);
      	if(ans==INF) { printf("No route\n"); continue; }
      	PrintPath(idx[b]);
      }
	return 0;
}
