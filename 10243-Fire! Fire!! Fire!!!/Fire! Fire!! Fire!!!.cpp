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
#define SZ 1002

/*problem id-10243
 *language-C++
 *
 *Minimum vertex cover ( প্রবলেম টা ১ চান্সে AC হবে চিন্তা করি নাই । )
 */

using namespace std;

set<int> AdjList[SZ];
int N,dp[SZ][3];
bool vis[SZ];

int min(int a,int b) { return a<b ? a : b; }

int MVC(int n,int state)
{
      int l=AdjList[n].size(),sum,x;
      if(!l) return 1;
      if(dp[n][state]!=-1) return dp[n][state];
      sum = (state==-1) ? 0 : 1;
      for(set<int>::iterator it=AdjList[n].begin();it!=AdjList[n].end();it++)
      {
            x=*it;
      	if(!vis[x])
      	{
      	      vis[n]=1;
      	      if(state==-1) sum+=MVC(x,1);
      	      else sum+=min(MVC(x,1),MVC(x,-1));
      	      vis[n]=0;
      	}
      }
      return dp[n][state]=sum;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d",&N) && N)
	{
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=N;i++) AdjList[i].clear();
		for(i=1;i<=N;i++)
		{
			scanf("%d",&x);
			while(x--)
			{
				scanf("%d",&y);
				AdjList[i].insert(y);
				AdjList[y].insert(i);
			}
		}
		printf("%d\n",min(MVC(1,1),MVC(1,-1)));
	}
	return 0;
}
