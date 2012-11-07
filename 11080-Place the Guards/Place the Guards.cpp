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

/*problem id-11080
 *
 *language-C++
 *
 */

using namespace std;

int N;
int M;
int black;
int white;
int Color[200];
vector<int> AdjList[200];

bool DFS(int n,int colr)
{
      if(Color[n]!=-1) return colr==Color[n];
      bool Bicolor=true;
      Color[n]=colr;
      if(colr) white++;
      else black++;
      for(int i=0,l=AdjList[n].size();i<l;i++) Bicolor = Bicolor && DFS(AdjList[n][i],!colr);
      return Bicolor;
}

int BiColorable()
{
      int total=0;
      int mini;
      bool flag=true;
      for(int i=0;i<N;i++)
      {
            if(Color[i]==-1)
            {
                  black=white=0;
                  flag=DFS(i,1);
                  if(!flag) return -1;
                  if(white<black) mini = white ? white : black;
                  else mini= black ? black : white;
                  total+=mini;
            }
      }
      return total;
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
	int x;
	int y;
	int ans;
	int guard[2];
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d %d",&N,&M);guard[0]=guard[1]=0;
      	for(i=0;i<N;i++) { AdjList[i].clear(); Color[i]=-1; }
      	while(M--)
      	{
      		scanf("%d %d",&x,&y);
      		AdjList[x].push_back(y);
      		AdjList[y].push_back(x);
      	}
      	ans=BiColorable();
      	if(ans==-1) {printf("-1\n");continue;}
      	else printf("%d\n",ans);
      }
	return 0;
}
