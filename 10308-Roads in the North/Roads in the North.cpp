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

#define ll long long int
#define INF 1<<30
#define SZ 10002

/*problem id-10308
 *
 *language-C++
 *
 */

using namespace std;

ll res;
vector<pair<int,int> > AdjList[SZ];

ll DFS(int n,int p)
{
      int i,l;
      ll ans,max=0;
      pair<int,int> tmp;
      for(i=0, l=AdjList[n].size();i<l;i++)
      {
            tmp=AdjList[n][i];
            if(tmp.first!=p)
            {
                  ans=DFS(tmp.first,n)+tmp.second;
                  if(ans+max>res) res=ans+max;
                  if(ans>max) max=ans;
            }
      }
      return max;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0;
	char a[]="dfs",*p=a;
	char line[20];
	while(1)
	{
	      for(i=1,res=0;i<SZ;i++) AdjList[i].clear();
		while((p=gets(line))!=NULL && line[0])
		{
			sscanf(line,"%d %d %d",&x,&y,&z);
                  AdjList[x].push_back(make_pair(y,z));
                  AdjList[y].push_back(make_pair(x,z));
		}
		x=DFS(1,-1);
		printf("%lld\n",res);
		if(p==NULL) break;
	}
	return 0;
}
