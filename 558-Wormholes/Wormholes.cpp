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
#define INF 1<<28
#define SZ 1002

/*problem id-558
 *
 *language-C++
 *
 */

using namespace std;

struct node
{
      int v,w;
};

int N,M,d[SZ],s[SZ];
vector<node> AdjList[SZ];

bool BellmanFord(int source)
{
      int i,j,k,l,v,x,flag;
      For(i,N) d[i]=INF, s[i]=AdjList[i].size();
      d[source]=0;
      For(k,N-1)
      {
            flag=0;
      	For(i,N)
      	{
      		For(j,s[i])
      		{
      			v=AdjList[i][j].v, x=AdjList[i][j].w;
      			if(d[i]+x<d[v])
      			{
      			      d[v]=d[i]+x;
      			      flag=1;
      			}
      		}
      	}
      	if(!flag) break;
      }
      For(i,N)
      {
      	For(j,s[i])
      	{
      		v=AdjList[i][j].v, x=AdjList[i][j].w;
      		if(d[i]+x<d[v]) return true;
      	}
      }
      return false;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0;
	node tmp;
	scanf("%d",&t);
	while(t--)
	{
	      scanf("%d %d",&N,&M);
	      For(i,N) AdjList[i].clear();
	      while(M--)
	      {
	      	scanf("%d %d %d",&x,&y,&z);
	      	tmp.v=y, tmp.w=z;
	      	AdjList[x].push_back(tmp);
	      }
	      printf("%s\n",BellmanFord(0)?"possible":"not possible");
	}
	return 0;
}
