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

#define SZ 222

/*problem id-10505
 *
 *language-C++
 *
 */

using namespace std;

int N,black,white,Color[SZ],vis[SZ],flag;
vector<int> AdjList[SZ];

int max(int a,int b) { return a>b ? a : b; }

void DFS(int n,int colr)
{
      vis[n]=1, Color[n]=colr;
      for(int i=0,l=AdjList[n].size();i<l;i++)
      {
            if(!vis[AdjList[n][i]]) DFS(AdjList[n][i],(colr+1)%2);
            else if(Color[AdjList[n][i]]==colr) Color[AdjList[n][i]]=2;
      }
      return;
}

int BiColorable()
{
      int i,j,total=0;
      for(i=0;i<N;i++)
      {
            if(!vis[i])
            {
                  black=white=0, flag=1;
                  DFS(i,1);
                  for(j=0;j<N;j++)
                  {
                  	if(vis[j]==1)
                  	{
                  	      if(Color[j]==2) flag=0;
                  	      else Color[j] ? white++ : black++;
                  	      vis[j]=2;
                  	}
                  }
                  total+=flag ? max(white,black) : 0;
            }
      }
      return total;
}

int main()
{
      int i,j,k,l,m,n,t,x,y,blank,test=0;
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d",&N);
      	memset(vis,0,SZ*sizeof(int));
      	memset(Color,-1,SZ*sizeof(int));
      	for(i=0;i<N;i++) AdjList[i].clear();
      	for(i=0;i<N;i++)
      	{
      	      scanf("%d",&m);
      		while(m--)
      		{
      			scanf("%d",&x);
                        AdjList[i].push_back(x-1);
                        AdjList[x-1].push_back(i);
      		}
      	}
      	printf("%d\n",BiColorable());
      }
	return 0;
}
