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

/*problem id-10150
 *
 *language-C++
 *
 */

using namespace std;

int len[25200],parent[25200],top;
char name[25200][25];
map<string,int> idx;

bool strdiff(char *a,char *b,int l1,int l2)
{
      int i,cnt=0;
      if(l1!=l2) return false;
      for(i=0;i<l1;i++) if(a[i]!=b[i]) cnt++;
      return cnt==1;
}

void PrintPath(int at)
{
      if(parent[at]!=-1) PrintPath(parent[at]);
      printf("%s\n",name[at]);
}

int BFS(int start,int end)
{
      int i,j,k,l,x,y,dis[25200],vis[25200];
      queue<int> BFSque;
      memset(vis,UNVISITED,25200*sizeof(int));
      for(i=0;i<top;i++) dis[i]=INF, parent[i]=-1;
      dis[start]=0; parent[start]=-1; BFSque.push(start); vis[start]=WAITING;
      while(!BFSque.empty() && vis[end]==UNVISITED)
      {
      	x=BFSque.front(); BFSque.pop();
      	for(i=0;i<top;i++)
      	{
      		if(vis[i]==UNVISITED)
      		{
      		      if(strdiff(name[x],name[i],len[x],len[i]))
                        {
                              dis[i]=dis[x]+1;
                              parent[i]=x;
                              vis[i]=WAITING;
                              BFSque.push(i);
                        }
      		}
      	}
      	vis[x]=VISITED;
      }
      return dis[end];
}

int main()
{
	int i,j,k,l,m,n,t,x,y,cnt,ans;
	bool blank=false;
	char temp[40],start[25],end[25];
      if(blank) putchar('\n');
      top=0, cnt=1;
      while(gets(temp) && temp[0])
      {
            strcpy(name[top],temp);
            idx[name[top]]=cnt++;
            len[top]=strlen(name[top]);
            top++;
      }
      while(gets(temp)!=NULL && temp[0])
      {
            if(blank) putchar('\n'); blank=true;
            sscanf(temp,"%s %s",start,end);
            ans=BFS(idx[start]-1,idx[end]-1);
            if(ans==INF) printf("No solution.\n");
            else PrintPath(idx[end]-1);
      }
	return 0;
}

