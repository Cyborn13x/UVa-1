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

/*problem id-341
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

int Source;
int Target;

struct compare
{
    bool operator()(const node& l, const node& r)
    {
        return l.d > r.d;
    }
};

void Path(int *n,int i)
{
    int j=i;
    if(n[i]!=-1) {i=n[i];Path(n,i);printf(" %d",n[j]);}
    return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int ser;
	int vt;
	int Nodes;
	int Edges;
	int dis[200];
	int root[200];
	bool vis[200];
	priority_queue<node,vector<node>,compare > Queue;
	map<int,vector<edge> > AdjList;
	edge e;
	node nd;
	char c;
	ser=1;
	while(scanf("%d",&Nodes)==1 && Nodes)
	{
	    memset(vis,false,sizeof(vis));
        for(i=0;i<20;i++) {root[i]=-1;dis[i]=INFINITY;}
	    AdjList.clear();
	    while(!Queue.empty()) Queue.pop();
	    for(j=1;j<=Nodes;j++)
	    {
            scanf("%d",&t);
            for(i=0;i<t;i++)
            {
                scanf("%d %d",&m,&k);
                e.u=j;e.v=m;e.w=k;
                AdjList[j].push_back(e);
            }
	    }
	    scanf("%d %d",&Source,&Target);
		dis[Source]=0;
		nd.v=Source;nd.d=0;
		Queue.push(nd);
		while(!vis[Target])
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
		    	    root[AdjList[vt][i].v]=vt;
		    	    nd.v=AdjList[vt][i].v;nd.d=dis[AdjList[vt][i].v];
		    	    Queue.push(nd);
		    	}
		    }
		    vis[vt]=true;
		}
		printf("Case %d: Path =",ser++);
		Path(root,Target);
		printf(" %d; %d second delay\n",Target,dis[Target]);
	}
	return 0;
}
