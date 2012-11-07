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

#define INF 10000000
#define VISITED 2
#define WAITING 1
#define UNVISITED 0

/*problem id-429
 *
 *language-C++
 *
 */

using namespace std;

int len[202],N,top;
bool AdjMat[202][202];
char name[202][15];
map<string,int> idx;

void Reset()
{
      memset(AdjMat,false,202*202*sizeof(bool));
      idx.clear();
      return;
}

bool strdiff(char *a,char *b,int l1,int l2)
{
      int i,cnt=0;
      if(l1!=l2) return false;
      for(i=0;i<l1;i++) if(a[i]!=b[i]) cnt++;
      return cnt==1;
}

void BuildMatrix()
{
      int i,j,k;
      for(i=0;i<top;i++)
      {
      	for(j=i+1;j<top;j++)
      	{
      		if(strdiff(name[i],name[j],len[i],len[j]))
      		{
      		      AdjMat[i][j]=AdjMat[j][i]=true;
      		}
      	}
      }
      return;
}

int BFS(int start,int end)
{
      int i,j,k,l,x,y,dis[202],vis[202];
      queue<int> BFSque;
      memset(vis,UNVISITED,202*sizeof(int));
      for(i=0;i<top;i++) dis[i]=INF;
      dis[start]=0; BFSque.push(start); vis[start]=WAITING;
      while(!BFSque.empty() && vis[end]==UNVISITED)
      {
      	x=BFSque.front(); BFSque.pop();
      	for(i=0;i<top;i++)
      	{
      		if(AdjMat[x][i] && vis[i]==UNVISITED)
      		{
                        dis[i]=dis[x]+1;
                        vis[i]=WAITING;
                        BFSque.push(i);
      		}
      	}
      	vis[x]=VISITED;
      }
      return dis[end];
}

int main()
{
	int i,j,k,l,m,n,t,x,y,testcase,cnt,ans;
	bool blank=false;
	char temp[30],start[15],end[15];
	scanf("%d",&testcase); getchar();getchar();
	while(testcase--)
	{
	      if(blank) putchar('\n');
	      top=0, cnt=1, blank=true;
		while(scanf("%s\n",name[top]) && name[top][0]!='*')
		{
		      idx[name[top]]=cnt++;
		      len[top]=strlen(name[top]);
			top++;
		}
		BuildMatrix();
		while(gets(temp)!=NULL && temp[0])
		{
			sscanf(temp,"%s %s",start,end);
			ans=BFS(idx[start]-1,idx[end]-1);
			printf("%s %s %d\n",start,end,ans);
		}
		Reset();
	}
	return 0;
}
