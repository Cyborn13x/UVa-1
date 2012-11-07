#include <iostream>
#include <sstream>
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

#define INF 1<<30
#define SZ 102

/*problem id-820
 *
 *language-C++
 *
 */

using namespace std;

int AdjMat[SZ][SZ],parent[SZ],N,M,flow;

int min(int a,int b) { return a<b ? a : b; }

void AugmentPath(int S,int t,int minEdge)
{
      if(t==S)
      {
            flow=minEdge;
            return;
      }
      if(parent[t]!=-1)
      {
            AugmentPath(S,parent[t],min(minEdge,AdjMat[parent[t]][t]));
            AdjMat[parent[t]][t]-=flow;
            AdjMat[t][parent[t]]+=flow;
      }
      return;
}

int EdmondsKarp(int S,int T)
{
      int i,j,k,l,tmp,MaxFlow=0;
      while(1)
      {
      	int dist[SZ]={0};
      	queue<int> q;
      	q.push(S), dist[S]=flow=0;
      	while(!q.empty())
      	{
      		tmp=q.front(); q.pop();
      		if(tmp==T) break;
      		for(i=0;i<N;i++)
      		{
      			if(AdjMat[tmp][i] && !dist[i])
      			{
      			      dist[i]=dist[tmp]+1;
      			      q.push(i);
      			      parent[i]=tmp;
      			}
      		}
      	}
      	AugmentPath(S,T,INF);
      	if(!flow) break;
      	MaxFlow+=flow;
      }
      return MaxFlow;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0,Source,Target;
      while(scanf("%d",&N) && N)
      {
            memset(AdjMat,0,SZ*SZ*sizeof(int));
            memset(parent,-1,SZ*sizeof(int));
      	scanf("%d %d %d",&Source,&Target,&l);
      	while(l--)
      	{
      		scanf("%d %d %d",&x,&y,&z);
      		AdjMat[x-1][y-1]+=z, AdjMat[y-1][x-1]+=z;
      	}
      	printf("Network %d\nThe bandwidth is %d.\n\n",++test,EdmondsKarp(Source-1,Target-1));
      }
	return 0;
}
