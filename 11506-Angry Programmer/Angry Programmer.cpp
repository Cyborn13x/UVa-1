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
#define IN(x) (2*(x))
#define OUT(x) (IN(x)+1)
#define INF (1<<30)
#define SZ 110

/*problem id-11506
 *
 *language-C++
 *
 */

using namespace std;

int adj[SZ][SZ],p[SZ],M,W,src,snk;

void Input()
{
      int i,j,x=M-2,u,v,w;
      CLEAR(adj);
      src=OUT(1), snk=IN(M);
      while(x--)
      {
      	scanf("%d %d",&u,&w);
            adj[IN(u)][OUT(u)]=w;
      }
      while(W--)
      {
      	scanf("%d %d %d",&u,&v,&w);
      	adj[OUT(u)][IN(v)]=adj[OUT(v)][IN(u)]=w;
      }
      return;
}

bool BFS()
{
      int i,u,v;
      queue<int> q;
      SET(p);
      q.push(src);
      while(!q.empty())
      {
      	u=q.front(); q.pop();
      	if(u==snk) return true;
      	for(v=src;v<=snk;v++)
      	{
      		if(adj[u][v] && p[v]==-1)
      		{
      		      p[v]=u;
      		      q.push(v);
      		}
      	}
      }
      return false;
}

int AugmentPath(int s,int t,int MinEdge)
{
      int x;
      if(t==s) return MinEdge;
      x=AugmentPath(s,p[t],min(MinEdge,adj[p[t]][t]));
      adj[p[t]][t]-=x;
      adj[t][p[t]]+=x;
      return x;
}

void MaxFlow()
{
      int i,j,k,x,y,z,MaximumFlow=0;
      while(BFS()) MaximumFlow+=(x=AugmentPath(OUT(1),IN(M),INF));
      printf("%d\n",MaximumFlow);
      return;
}

int main()
{
      while(scanf("%d %d",&M,&W) && (M || W))
      {
      	Input();
      	MaxFlow();
      }
	return 0;
}
