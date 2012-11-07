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
#include <algorithm>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1000000000
#define SZ 102

/*problem id-11848
 *
 *language-C++
 *
 */

using namespace std;

struct nd
{
      int v;
      double w;
};

int node;
double g1[SZ][SZ],g2[SZ][SZ],dis[SZ],A;

bool operator<(nd x,nd y)
{
      return x.w>y.w;
}

void Dijkstra(int source,int target)
{
      int i,j,k,l,u,x;
      double d,cost;
      nd tmp;
      priority_queue<nd> pq;
      while(!pq.empty()) pq.pop();
      For(i,node) dis[i]=(double)INF;
      dis[source]=0;
      tmp.v=source, tmp.w=0;
      pq.push(tmp);
      while(!pq.empty())
      {
      	tmp=pq.top();
      	pq.pop();
      	u=tmp.v, d=tmp.w;
      	if(u==target) { printf("%d\n",(int)dis[target]); return; }
      	For(i,node)
      	{
      		if(g1[u][i]==-1 && g2[u][i]==-1) continue;
      		if(g1[u][i]!=-1 && g2[u][i]!=-1) cost=A*g1[u][i]+(1-A)*g2[u][i];
      		else cost=max(g1[u][i],g2[u][i]);
      		if(d+cost<dis[i])
      		{
      		      dis[i]=d+cost;
      		      tmp.v=i, tmp.w=dis[i];
      		      pq.push(tmp);
      		}
      	}
      }
      return;
}

int main()
{
	int i,j,k,l,m1,m2,n,t,x,y,blank=0,test=0;
	double w;
	while(scanf("%d %d %d %d",&node,&m1,&m2,&k))
	{
		if(node==-1 && m1==-1 && m2==-1 && k==-1) break;
		For(i,node) For(j,node) g1[i][j]=g1[j][i]=g2[i][j]=g2[j][i]=-1;
		For(i,m1)
		{
			scanf("%d %d %lf",&x,&y,&w);
			g1[x][y]=g1[y][x]=w;
		}
		For(i,m2)
		{
			scanf("%d %d %lf",&x,&y,&w);
			g2[x][y]=g2[y][x]=w;
		}
		while(k--)
		{
			scanf("%lf",&A);
                  Dijkstra(0,node-1);
		}
	}
	return 0;
}
