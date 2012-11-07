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
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<28
#define SZ 102

/*problem id-10557
 *
 *language-C++
 *
 */

using namespace std;

int e[SZ],mark[SZ],d[SZ];
bool vis[SZ];
vector<int> AdjList[SZ];

void DFS(int n)
{
      if(vis[n]) return;
      vis[n]=true, mark[n]=1;
      for(int i=0,l=AdjList[n].size();i<l;i++) DFS(AdjList[n][i]);
      return;
}

bool BellmanFord(int n)
{
      int i,j,k,l,v,s[SZ];
      Clear(vis,0);
      Clear(mark,0);
      DFS(0);
      if(!mark[n-1]) return false;
      For(i,n) d[i]=INF, s[i]=AdjList[i].size();
      d[0]=-100, e[n-1]=0;
      For(k,20000)
      {
      	For(i,n)
      	{
      		For(j,s[i])
      		{
      			v=AdjList[i][j];
      			if(d[i]>=0) continue;
      			if(d[i]+e[v]<d[v]) d[v]=d[i]+e[v];
      			if(d[n-1]<INF) return true;
      		}
      	}
      }
      return false;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d",&n) && n>=0)
	{
		For(i,n)
		{
		      AdjList[i].clear();
			scanf("%d %d",&x,&k);
			e[i]=-x;
			while(k--)
			{
				scanf("%d",&x);
				AdjList[i].push_back(x-1);
			}
		}
		printf("%s\n",BellmanFord(n)?"winnable":"hopeless");
	}
	return 0;
}
