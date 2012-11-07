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

/*problem id-459
 *
 *language-C++
 *
 */

using namespace std;

vector<int> v[26];
int size[26];
bool vis[26];
char a[5];
char c;

void DFS(int x)
{
      if(vis[x]) return;
      vis[x]=true;
      for(int i=0;i<size[x];i++) DFS(v[x][i]);
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
	int res;
	bool flag=false;
	scanf("%d",&t);
	getchar();
	getchar();
	while(t--)
	{
	      for(i=0;i<26;i++) v[i].clear();
		cin >> c;res=0;
		getchar();
		if(flag) printf("\n");
		flag=true;
		while(gets(a)!=NULL && a[0])
		{
			v[a[0]-'A'].push_back(a[1]-'A');
			v[a[1]-'A'].push_back(a[0]-'A');
		}
		for(i=0;i<=c-'A';i++) size[i]=v[i].size();
		memset(vis,false,sizeof(vis));
		for(i=0;i<=c-'A';i++) if(!vis[i]) {res++;DFS(i);}
		printf("%d\n",res);
	}
	return 0;
}
