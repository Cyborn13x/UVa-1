#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-10004
 *
 *language-C++
 *
 */

using namespace std;

int node;
int edge;
int clr[200];
bool flag;
vector<int> v[200];

void DFS(int n,int color)
{
      if(clr[n]!=-1)
      {
            if(clr[n]==color) {flag=false;}
            return;
      }
      color=!color;
      clr[n]=color;
      int l=v[n].size();
      for(int i=0;i<l && flag;i++) DFS(v[n][i],color);
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
	bool color;
	while(scanf("%d",&node)==1 && node)
	{
		scanf("%d",&edge);
		for(i=0;i<node;i++)
		{
		      v[i].clear();
		      clr[i]=-1;
		}
		for(i=0;i<edge;i++)
		{
			scanf("%d %d",&m,&n);
			v[m].push_back(n);
			v[n].push_back(m);
		}
		flag=true;
		color=true;
            DFS(0,color);
		if(flag) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}
