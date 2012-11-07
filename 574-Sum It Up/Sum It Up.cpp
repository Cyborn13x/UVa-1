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

/*problem id-574
 *
 *language-ANSI C
 *
 */

using namespace std;

int N;
int V;
int top;
int a[15];
int ans[15];
int used[105];
bool flag;
map<vector<int>,bool> mp;

void DFS(int sum,int idx)
{
      int i;
      int t;
      if(sum>V) return;
      if(sum==V)
      {
            vector<int> tmp;
            for(i=top=t=0;i<N && t<V;i++) if(used[i]) {tmp.push_back(a[i]);t+=a[i];}
            if(!mp[tmp])
            {
                  printf("%d",tmp[0]);
                  for(i=1,t=tmp.size();i<t;i++) printf("+%d",tmp[i]);
                  printf("\n");
                  mp[tmp]=true;
                  flag=true;
            }
            return;
      }
      for(i=idx;i<N;i++)
      {
      	if(!used[i])
      	{
                  used[i]=1;
                  DFS(sum+a[i],i+1);
                  used[i]=0;
      	}
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
	while(scanf("%d %d",&V,&N) && N)
	{
	      mp.clear();
	      for(i=0;i<N;i++) scanf("%d",&a[i]);
	      sort(a,a+N); reverse(a,a+N);
            printf("Sums of %d:\n",V);
	      flag=false;
	      DFS(0,0);
	      if(!flag) printf("NONE\n");
	}
	return 0;
}
