#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

#define INFINITY 1000000000

/*problem id-10986
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
    int u;
    int v;
    int w;
}edge;

typedef struct
{
    int v;
    int d;
}node;

struct compare
{
    bool operator()(const node& l, const node& r)
    {
        return l.d > r.d;
    }
};

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int vt;
	int Nodes;
	int Edges;
	int Source;
	int Target;
	int dis[20000];
	bool vis[20000];
	priority_queue<node,vector<node>,compare > Queue;
	map<int,vector<edge> > AdjList;
	edge e;
	node nd;
	scanf("%d",&t);
	k=1;
	while(t--)
	{
	    memset(vis,false,sizeof(vis));
	    memset(dis,INFINITY,sizeof(dis));
	    for(i=0;i<20000;i++) dis[i]=INFINITY;
	    AdjList.clear();
	    while(!Queue.empty()) Queue.pop();
		scanf("%d %d %d %d",&Nodes,&Edges,&Source,&Target);
		for(i=0;i<Edges;i++)
		{
			scanf("%d %d %d",&l,&m,&n);
			e.u=l;e.v=m;e.w=n;
			AdjList[l].push_back(e);
			e.u=m;e.v=l;e.w=n;
			AdjList[m].push_back(e);
		}
		dis[Source]=0;
		nd.v=Source;nd.d=0;
		Queue.push(nd);
		while(!Queue.empty())
		{
		    nd=Queue.top();
		    Queue.pop();
		    vt=nd.v;
		    l=AdjList[vt].size();
		    for(i=0;i<l;i++)
		    {
		    	if(!vis[AdjList[vt][i].v] && dis[vt]+AdjList[vt][i].w<dis[AdjList[vt][i].v])
		    	{
		    	    dis[AdjList[vt][i].v]=dis[vt]+AdjList[vt][i].w;
		    	    nd.v=AdjList[vt][i].v;nd.d=dis[AdjList[vt][i].v];
		    	    Queue.push(nd);
		    	}
		    }
		    vis[vt]=true;
		}
		printf("Case #%d: ",k++);
		if(dis[Target]!=INFINITY) printf("%d\n",dis[Target]);
		else printf("unreachable\n");
	}
	return 0;
}
