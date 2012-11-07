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

#define INF 1<<30
#define SZ 10005

using namespace std;

int N, M, vis[SZ], lev[SZ], low[SZ], TotalSCC, scc[SZ], tarjan[SZ], cnt, num;
vector<int> AdjList[SZ];

int min(int a,int b) { return a<b ? a : b; }

int TarjanSCC(int n)
{
      int i,l,x;
      if(lev[n]!=-1) return low[n];
      low[n]=lev[n]=num++;
      tarjan[cnt++]=n;
      for(i=0,l=AdjList[n].size();i<l;i++)
      {
      	x=AdjList[n][i];
      	if(scc[x]==-1) low[n]=min(low[n],TarjanSCC(x));
      }
      if(lev[n]==low[n])
      {
            while(scc[n]!=TotalSCC) scc[tarjan[--cnt]]=TotalSCC;
            TotalSCC++;
      }
      return low[n];
}

int DFS(int n,int top)
{
      int i,l=AdjList[n].size(),x,back=0;
      vis[n]=1;
      for(i=0;i<l;i++)
      {
            x=AdjList[n][i];
      	if(vis[x]==1)
      	{
      	      back=1;
      	      if(lev[x]<top) return 0;
      	}
      }
      if(back) top=lev[n];
      for(i=0;i<l;i++)
      {
            x=AdjList[n][i];
      	if(!vis[x]) { if(!DFS(x,top)) return 0; }
      	else if(vis[x]==2) return 0;
      }
      vis[n]=2;
      return 1;
}

void Reset()
{
      int i;
      TotalSCC=cnt=num=0;
      memset(vis,0,SZ*sizeof(int));
      memset(lev,-1,SZ*sizeof(int));
      memset(scc,-1,SZ*sizeof(int));
      for(i=TotalSCC=0;i<SZ;i++) AdjList[i].clear();
      return;
}

int main()
{
      //freopen("in.txt","r",stdin);
      int i,j,k,l,t,x,y,blank=0,test=0;
      scanf("%d",&t);
	while(t--)
	{
	      scanf("%d %d",&N,&M);
	      Reset();
		for(i=0;i<M;i++)
		{
			scanf("%d %d",&x,&y);
			AdjList[x].push_back(y);
		}
		for(i=0;i<N;i++) TarjanSCC(i);
		if(TotalSCC==1)
		{
                  if(DFS(0,-1)) printf("YES\n");
                  else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}
