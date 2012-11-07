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

/*problem id-544
 *
 *language-ANSI C
 *
 */

using namespace std;

typedef struct
{
      int u;
      int v;
      int w;
}edge;

int parent[202];
edge list[19905];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

int IsUnion(int A,int B)
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
      return a.w>b.w;
}

int main()
{
      freopen("in.txt","r",stdin);
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int d;
	int ind;
	int i1;
	int i2;
	int MinMax;
	char a[50];
	char b[50];
	map<string,int> mp;x=1;
      while(scanf("%d %d",&n,&m) && (n || m))
      {
            mp.clear();ind=1;MinMax=20000000;
      	for(i=1;i<=n;i++) parent[i]=i;
      	for(i=0;i<m;i++)
      	{
      	      scanf("%s %s %d",a,b,&d);
      	      if(!mp[a]) mp[a]=ind++;
      	      if(!mp[b]) mp[b]=ind++;
      	      list[i].u=mp[a];
      	      list[i].v=mp[b];
      	      list[i].w=d;
      	}
      	scanf("%s %s",a,b);i1=mp[a];i2=mp[b];
      	sort(list,list+m,cmp);
      	for(i=k=0;i<m && k<n-1 && !IsUnion(i1,i2);i++)
      	{
      		if(!IsUnion(list[i].u,list[i].v))
      		{
      		      MakeUnion(list[i].u,list[i].v);
      		      k++;
      		      if(list[i].w<MinMax) MinMax=list[i].w;
      		}
      	}
      	printf("Scenario #%d\n%d tons\n\n",x++,MinMax);
      }
	return 0;
}

