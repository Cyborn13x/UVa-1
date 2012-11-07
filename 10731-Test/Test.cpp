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

/*problem id-10731
 *
 *language-C++
 *
 */

using namespace std;

bool vis[26];
bool used[26];
set<int> tmp;
set<set<int> > result;
set<int>::iterator it2;
set<set<int> >::iterator it1;
vector<int> TopoSort;
vector<int> AdjList[26];
vector<int> RevAdjList[26];

void DFS1(int n)
{
      if(vis[n]) return;
      vis[n]=true;
      for(int i=0,l=AdjList[n].size();i<l;i++) DFS1(AdjList[n][i]);
      TopoSort.push_back(n);
      return;
}

void DFS2(int n)
{
      if(!vis[n]) return;
      vis[n]=false; tmp.insert(n);
      for(int i=0,l=RevAdjList[n].size();i<l;i++) DFS2(RevAdjList[n][i]);
      return;
}

void Reset()
{
      int i;
      memset(vis,false,sizeof(vis));
      memset(used,false,sizeof(used));
      for(i=0,TopoSort.clear();i<26;i++)
      {
            AdjList[i].clear();
            RevAdjList[i].clear();
      }
      tmp.clear();
      result.clear();
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
	int x;
	int y;
	bool blank=false;
	bool space;
	char c;
	char a[6];
	while(scanf("%d%*c",&n) && n)
	{
	      if(blank) putchar('\n'); blank=true;
	      Reset();
		for(j=0;j<n;j++)
		{
			for(i=0;i<6;i++) { scanf("%c%*c",&a[i]); used[a[i]-'A']=true; }
			for(i=0;i<5;i++)
			{
			      if(a[i]!=a[5])
			      {
			            AdjList[a[i]-'A'].push_back(a[5]-'A');
			            RevAdjList[a[5]-'A'].push_back(a[i]-'A');
			      }
			}
		}
		for(i=0;i<26;i++) if(!vis[i] && used[i]) DFS1(i);
		for(i=TopoSort.size()-1;i>=0;i--)
		{
		      if(vis[TopoSort[i]])
		      {
		            tmp.clear();
		            DFS2(TopoSort[i]);
		            result.insert(tmp);
                  }
		}
		for(it1=result.begin();it1!=result.end();it1++)
		{
			for(it2=it1->begin(),space=false;it2!=it1->end();it2++)
			{
				if(space) putchar(' ');
				c=*it2+'A'; putchar(c); space=true;
			}
			putchar('\n');
		}
	}
	return 0;
}
