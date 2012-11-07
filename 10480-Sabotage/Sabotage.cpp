#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
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

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 55

/*problem id-10480
 *
 *language-C++
 *
 */

using namespace std;

int adj[SZ][SZ],p[SZ],d[SZ],N,M,flow;
bool used[SZ][SZ];
vector<pair<int,int> > ans;

void Input()
{
      int i,j,x,y,z;
      CLEAR(used);
      CLEAR(adj);
      ans.clear();
      while(M--)
      {
      	scanf("%d %d %d",&x,&y,&z);
      	adj[x][y]=adj[y][x]=z;
      	used[x][y]=used[y][x]=true;
      }
      return;
}

int BFS()
{
      int i,j,u,v;
      queue<int> q;
      SET(p);
      FORI(i,1,N) d[i]=INF;
      q.push(1);
      d[1]=0;
      while(!q.empty())
      {
      	u=q.front(); q.pop();
      	if(u==2) return 1;
      	FORI(v,1,N)
      	{
      		if(adj[u][v] && d[v]==INF)
      		{
      		      d[v]=d[u]+1;
      		      p[v]=u;
      		      q.push(v);
      		}
      	}
      }
      return 0;
}

void AugmentPath(int S,int t,int MinFlow)
{
      if(S==t) { flow=MinFlow; return; }
      AugmentPath(S,p[t],min(MinFlow,adj[p[t]][t]));
      adj[p[t]][t]-=flow;
      adj[t][p[t]]+=flow;
      return;
}

void MaxFlow()
{
      int i,j,MaximumFlow=0,u,v;
      bool in[SZ];
      queue<int> q;
      CLEAR(in);
      while(BFS()) AugmentPath(1,2,INF);
      q.push(1);
      in[1]=true;
      while(!q.empty())
      {
      	u=q.front(); q.pop();
      	FORI(v,1,N)
      	{
      		if(adj[u][v] && !in[v])
      		{
      		      in[v]=true;
      		      q.push(v);
      		}
      	}
      }
      FORI(i,1,N)
      {
      	FORI(j,1,N)
      	{
      		if(used[i][j] && !adj[i][j] && in[i] && !in[j])
      		{
      		      printf("%d %d\n",i,j);
      		}
      	}
      }
      printf("\n");
      return;
}

int main()
{
      while(scanf("%d %d",&N,&M) && (N||M))
      {
      	Input();
      	MaxFlow();
      }
	return 0;
}
