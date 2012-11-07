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

using namespace std;

int N,cnt,low[300],level[300];
bool bridge[300][300];
vector<int> AdjList[300];

inline int min(int a,int b) { return a<b ? a : b; }

void DFS(int n)
{
      int i,l,x;
      low[n]=level[n];
      for(i=0,l=AdjList[n].size();i<l;i++)
      {
      	x=AdjList[n][i];
      	if(level[x]==-1)
      	{
      	      level[x]=level[n]+1;
      	      DFS(x);
      	      low[n]=min(low[n],low[x]);
      	      if(low[x]>level[n]) { cnt++; bridge[n][x]=bridge[x][n]=true; }
      	}
      	else if(level[x]<level[n]-1) low[n]=min(low[n],level[x]);
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank;
      while(scanf("%d",&N)!=EOF)
      {
            memset(bridge,false,sizeof(bridge));
      	for(i=0;i<N;i++) AdjList[i].clear();
      	for(i=0;i<N;i++)
      	{
      		scanf("%d (%d)",&n,&m);
      		for(j=0;j<m;j++)
      		{
      			scanf("%d",&x);
      			AdjList[n].push_back(x);
      			AdjList[x].push_back(n);
      		}
      	}
      	for(i=cnt=0;i<N;i++) level[i]=-1;
      	for(i=0;i<N;i++) if(level[i]==-1) { level[i]=0; DFS(i); }
      	printf("%d critical links\n",cnt);
      	for(i=0;i<N;i++)
      	{
      		for(j=i+1;j<N;j++)
      		{
      			if(bridge[i][j])
      			{
      			      printf("%d - %d\n",i,j);
      			}
      		}
      	}
      	printf("\n");
      }
	return 0;
}
