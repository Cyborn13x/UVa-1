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

#define INF 200000

/*problem id-924
 *
 *language-C++
 *
 */

using namespace std;

int boom[2500];
bool a[2500][2500];
bool known[2500];

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
	int N;
	int S;
	int MaxBoom;
	int dis[2500];
	queue<int> q;

      scanf("%d",&N);
      for(i=0;i<N;i++)
      {
      	scanf("%d",&m);
      	if(m) known[i]=true;
      	while(m--)
      	{
      		scanf("%d",&x);
      		a[i][x]=true;
      	}
      }
      scanf("%d",&t);
      while(t--)
      {
            memset(boom,0,sizeof(boom));
            for(i=0;i<N;i++) dis[i]=INF;
            while(!q.empty()) q.pop();
      	scanf("%d",&S);
      	q.push(S);dis[S]=0;
      	while(!q.empty())
      	{
      		x=q.front();q.pop();
      		for(i=0;i<N;i++)
      		{
      			if(a[x][i] && dis[i]==INF)
      			{
      			      boom[(dis[i]=dis[x]+1)]++;
      			      q.push(i);
      			}
      		}
      	}
      	if(!known[S]) { printf("0\n"); continue; }
      	for(i=1,MaxBoom=1;i<N;i++) MaxBoom = boom[i]>boom[MaxBoom] ? i : MaxBoom;
      	printf("%d %d\n",boom[MaxBoom],MaxBoom);
      }
	return 0;
}
