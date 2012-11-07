#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-1197
 *
 *language-C++
 *
 */

using namespace std;

int suspect;
int lenNd[30003];
int lenGr[501];
bool visNd[30003];
bool visGr[502];
int AdjList[30003][501];
vector<int> group[501];

void DFS(int grp)
{
      if(visGr[grp]) return;
      visGr[grp]=true;
      for(int i=0;i<lenGr[grp];i++) if(!visNd[group[grp][i]]) {suspect++;visNd[group[grp][i]]=true;}
      for(int i=0;i<lenGr[grp];i++)
      {
            int tmp=group[grp][i];
            for(int j=0;j<lenNd[tmp];j++) DFS(AdjList[tmp][j]);
      }
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
	while(scanf("%d %d",&n,&m)==2)
	{
		if(!n && !m) break;
		memset(visNd,false,sizeof(visNd));
		memset(visGr,false,sizeof(visGr));
		memset(lenNd,0,sizeof(lenNd));
		for(i=0;i<m;i++) group[i].clear();
		for(i=0;i<m;i++)
		{
		      scanf("%d",&l);lenGr[i]=l;
		      for(j=0;j<l;j++)
		      {
		            scanf("%d",&y);
                        group[i].push_back(y);
                        AdjList[y][lenNd[y]++]=i;
		      }
		}
		suspect=0;
		for(i=0;i<lenNd[0];i++) DFS(AdjList[0][i]);
		printf("%d\n",!suspect?1:suspect);
	}
	return 0;
}
