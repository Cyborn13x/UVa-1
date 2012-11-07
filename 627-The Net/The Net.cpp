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

#define INF 10000000
#define WHITE 0
#define GREY 1
#define BLACK 2

/*problem id-627
 *
 *language-C++
 *
 */

using namespace std;

int cnt;
int space;
int dis[302];
int vis[302];
int path[302];
int parent[302];
queue<int> BFSque;
vector<int> AdjList[301];

void BuildPath(int end)
{
      if(parent[end]!=end) BuildPath(parent[end]);
      if(space) printf(" %d",end);
      else { printf("%d",end); space=1; }
      return;
}

bool BFS(int start,int end)
{
      int i;
      int j;
      int k;
      int l;
      int x;
      int y;
      memset(vis,0,sizeof(vis));
      for(i=1;i<=300;i++) { dis[i]=INF; parent[i]=i; }
      while(!BFSque.empty()) BFSque.pop();
      BFSque.push(start); dis[start]=0; vis[start]=GREY; parent[start]=start;
      while(!BFSque.empty() && vis[end]==WHITE)
      {

      	x=BFSque.front(); BFSque.pop();
      	for(i=0,l=AdjList[x].size();i<l;i++)
      	{
      		y=AdjList[x][i];
      		if(vis[y]==WHITE)
      		{
      		      dis[y]=dis[x]+1;
      		      BFSque.push(y);
      		      vis[y]=GREY;
      		      parent[y]=x;
      		}
      	}
      	vis[x]=BLACK;
      }
      return dis[end]!=INF;
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
	int start;
	int end;
	bool flag;
	char *p;
	char tmp[1000];
	while(scanf("%d",&n)!=EOF)
	{
	      for(i=1;i<=n;i++) { AdjList[i].clear(); }
		for(i=0;i<n;i++)
		{
			scanf("%s",tmp);
			p=strtok(tmp,"-,");
			x=atoi(p);
			p=strtok(NULL,"-,");
			while(p!=NULL)
			{
				y=atoi(p);
				AdjList[x].push_back(y);
				p=strtok(NULL,"-,");
			}
		}
		scanf("%d",&m);
		printf("-----\n");
		while(m--)
		{
			scanf("%d %d",&start,&end);
			flag=BFS(start,end);
			if(!flag) { printf("connection impossible\n"); continue; }
			space=cnt=0;
			BuildPath(end);
			printf("\n");
		}
	}
	return 0;
}
