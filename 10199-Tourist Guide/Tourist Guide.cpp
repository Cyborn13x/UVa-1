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

/*problem id-10199
 *
 *language-C++
 *
 */

using namespace std;

int N,child[102],low[102],level[102];
bool articul[102];
char name[102][35];
map<string,int> idx;
vector<int> AdjList[102];

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
      	      child[n]++;
      	      DFS(x);
      	      low[n]=min(low[n],low[x]);
      	      if(level[n]>0 && low[x]>=level[n]) articul[n]=true;
      	}
      	else if(level[x]<level[n]-1) low[n]=min(low[n],level[x]);
      }
      if(!level[n] && child[n]>=2) articul[n]=true;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,ans,blank=0,test=0;
	char a[35],b[35];
	set<string> res;
	set<string>::iterator it;
	while(scanf("%d",&N) && N)
	{
	      if(blank) putchar('\n');
		for(i=blank=1;i<=N;i++)
		{
			scanf("%s",name[i]);
			idx[name[i]]=i;
		}
		scanf("%d",&n);
		for(i=ans=0;i<n;i++)
		{
			scanf("%s %s",a,b);
			x=idx[a], y=idx[b];
			AdjList[x].push_back(y);
			AdjList[y].push_back(x);
		}
		for(i=2,level[1]=0;i<=N;i++) level[i]=-1;
		DFS(1);
		for(i=2;i<=N;i++) if(level[i]==-1) { level[i]=0; DFS(i); }
		for(i=1,res.clear();i<=N;i++) if(articul[i]) { res.insert(name[i]); ans++; }
		printf("City map #%d: %d camera(s) found\n",++test,ans);
		for(it=res.begin();it!=res.end();it++) cout << *it <<endl;
		memset(child,0,102*sizeof(int));
		memset(articul,false,102*sizeof(bool));
		for(i=1,idx.clear();i<=N;i++) AdjList[i].clear();
	}
	return 0;
}
