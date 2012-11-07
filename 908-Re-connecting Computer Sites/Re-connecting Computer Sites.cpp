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

using namespace std;

#define N 1000002

/*problem id-908
 *
 *language-C++
 *
 */

typedef struct
{
      int u;
      int v;
      int w;
}edge;


int parent[N];
vector<edge> EdgeList;

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

bool IsUnion(int A,int B)
{
      return FindParent(A)==FindParent(B);
}

void MakeUnion(int A,int B)
{
      parent[FindParent(A)]=FindParent(B);
      return;
}

bool cmp(edge a,edge b)
{
      return a.w<b.w;
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
	unsigned long long int T;
	unsigned long long int ans;
      bool blank=false;
      edge tmp;
      while(scanf("%d",&n)!=EOF)
      {
            if(blank) printf("\n"); blank=true;
      	for(i=1;i<=n;i++) parent[i]=i;
      	for(i=1,T=0LL;i<n;i++) { scanf("%*d %*d %d",&x); T+=(unsigned long long int)x; }
      	printf("%llu\n",T);
      	scanf("%d",&k);
      	for(i=0,EdgeList.clear();i<k;i++)
      	{
      		scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.w);
      		EdgeList.push_back(tmp);
      	}
      	scanf("%d",&m);
      	for(i=0;i<m;i++)
      	{
      		scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.w);
      		EdgeList.push_back(tmp);
      	}
      	sort(EdgeList.begin(),EdgeList.begin()+m+k,cmp);
      	for(i=0,ans=0LL,l=m+k;i<l;i++)
      	{
      	      tmp=EdgeList[i];
      		if(!IsUnion(tmp.u,tmp.v))
      		{
      		      MakeUnion(tmp.u,tmp.v);
      		      ans+=(unsigned long long int)tmp.w;
      		}
      	}
      	printf("%llu\n",ans);
      }
	return 0;
}
