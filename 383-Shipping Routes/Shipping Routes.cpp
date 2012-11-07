#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

#define N  35
#define INF 100000
#define WHITE 0
#define GREY 1
#define BLACK 2

/*problem id-383
 *
 *language-C++
 *
 */

using namespace std;

int m;
int n;
int p;
int dis[N];
int vis[N];
map<string,int> idx;
vector<int> AdjList[N];

int BFS(int start,int end)
{
      register int i;
      int l;
      int x;
      int y;
      queue<int> BFSque;
      memset(vis,WHITE,N*sizeof(vis[0]));
      for(i=1;i<=n;i++) dis[i]=INF;
      BFSque.push(start); vis[start]=GREY; dis[start]=0;
      while(!BFSque.empty() && vis[end]==WHITE)
      {
      	x=BFSque.front(); BFSque.pop();
      	for(i=0,l=AdjList[x].size();i<l;i++)
      	{
      		y=AdjList[x][i];
      		if(vis[y]==WHITE)
      		{
      		      vis[y]=GREY;
      		      dis[y]=dis[x]+1;
      		      BFSque.push(y);
      		}
      	}
      	vis[x]=BLACK;
      }
      return dis[end];
}

int main()
{
	register int i;
	int j;
	int k;
	int l;
	int t;
	int x;
	int y;
	int cnt;
	int ans;
	char a[5];
	char b[5]; k=1;
	printf("SHIPPING ROUTES OUTPUT\n");
	scanf("%d",&t);
	while(t--)
	{
		printf("\nDATA SET  %d\n\n",k++);
		scanf("%d %d %d",&n,&m,&p);
		for(i=1,idx.clear();i<=n;i++) AdjList[i].clear();
		for(i=cnt=1;i<=n;i++) { scanf("%s",a); idx[a]=cnt++; }
		for(i=0;i<m;i++)
		{
			scanf("%s %s",a,b);
			AdjList[idx[a]].push_back(idx[b]);
			AdjList[idx[b]].push_back(idx[a]);
		}
		for(i=0;i<p;i++)
		{
			scanf("%d %s %s",&x,a,b);
			ans=BFS(idx[a],idx[b]);
			ans==INF ? printf("NO SHIPMENT POSSIBLE\n") : printf("$%d\n",x*ans*100);
		}
	}
	printf("\nEND OF OUTPUT\n");
	return 0;
}
