#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

#define INF -10
#define MAX 1000000

/*problem id-336
 *
 *language-C++
 *
 */

using namespace std;

int seen[MAX];

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
	int edge;
	int start;
	int ttl;
	int dis[35];
	int index;
	bool vis[35];
	vector<int> AdjList[35];
	queue<int> BFSqueue;
	j=1;
	while(scanf("%d",&edge)==1 && edge)
	{
	    index=1;
	    memset(seen,0,sizeof(seen));
	    for(i=0;i<32;i++) AdjList[i].clear();
	    for(i=0;i<edge;i++)
		{

			scanf("%d %d",&x,&y);
			if(!seen[x]) seen[x]=index++;
			if(!seen[y]) seen[y]=index++;
			AdjList[seen[x]].push_back(seen[y]);
			AdjList[seen[y]].push_back(seen[x]);
		}
		while(scanf("%d %d",&start,&ttl)==2)
		{

		    if(!start && !ttl) break;
		    memset(vis,false,sizeof(vis));
		    for(i=0;i<35;i++) dis[i]=-1;
		    while(!BFSqueue.empty()) BFSqueue.pop();
            BFSqueue.push(seen[start]);
            vis[seen[start]]=true;
            dis[seen[start]]=0;
            while(!BFSqueue.empty())
            {
            	x=BFSqueue.front();
            	BFSqueue.pop();
            	l=AdjList[x].size();
            	for(i=0;i<l;i++)
            	{
            		if(!vis[AdjList[x][i]])
            		{
            		    vis[AdjList[x][i]]=true;
            		    dis[AdjList[x][i]]=dis[x]+1;
            		    BFSqueue.push(AdjList[x][i]);
            		}
            	}
            }
            k=0;
            for(i=1;i<index;i++) if(dis[i]>ttl || dis[i]==-1) k++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",j++,k,start,ttl);
		}
    }
	return 0;
}
