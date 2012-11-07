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

/*problem id-315
 *
 *language-C++
 *
 */

using namespace std;

int low[100],level[100],child[100],N;
bool articul[100];
vector<int> AdjList[100];

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
	int i,j,k,l,m,n,t,x,y,ans,blank;
	char tmp[500],*p;
	while(scanf("%d\n",&N) && N)
	{
	      while(gets(tmp) && tmp[0]!='0')
	      {
	      	p=strtok(tmp," ");
	      	x=atoi(p)-1;
	      	p=strtok(NULL," ");
	      	while(p!=NULL)
	      	{
	      		y=atoi(p)-1;
	      		AdjList[x].push_back(y);
	      		AdjList[y].push_back(x);
	      		p=strtok(NULL," ");
	      	}
	      }
	      for(i=0;i<N;i++) level[i]=-1;
	      level[0]=ans=0;
	      DFS(0);
	      for(i=0;i<N;i++) if(articul[i]) ans++;
	      printf("%d\n",ans);
		for(i=0;i<N;i++) AdjList[i].clear();
		memset(child,0,100*sizeof(int));
		memset(articul,false,100*sizeof(bool));
	}
	return 0;
}
