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

/*problem id-11710
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
      int u;
      int v;
      int w;
}edge;

int parent[500];
edge list[80000];

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

bool cmp(edge A,edge B)
{
      return (A.w>=B.w) ? false : true;
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
	int cost;
	char a[100];
	char b[100];
	map<string,int> mp;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
		mp.clear();cost=k=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",a);
			mp[a]=i;
			parent[i]=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%s %s %d",a,b,&l);
			list[i].u=mp[a];
			list[i].v=mp[b];
			list[i].w=l;
		}
		scanf("%s",a);
		sort(list,list+m,cmp);
		for(i=0;i<m && k<n-1;i++)
		{
			if(!IsUnion(list[i].u,list[i].v))
			{
			      MakeUnion(list[i].u,list[i].v);
			      cost+=list[i].w;k++;
			}
		}
		if(k!=n-1) printf("Impossible\n");
		else printf("%d\n",cost);
	}
	return 0;
}
