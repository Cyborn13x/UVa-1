#include <iostream>
#include <sstream>
#include <fstream>
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

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 10000

/*problem id-538
 *
 *language-C++
 *
 */

using namespace std;

struct man
{
      int v;
      char name[SZ];
};

int cmp(const void *a,const void *b)
{
      return (*(man *)b).v-(*(man *)a).v;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a[SZ],b[SZ];
	map<string,int> idx;
	man list[23];
	while(scanf("%d %d",&n,&m) && (n||m))
	{
		idx.clear();
		For(i,n)
		{
			scanf("%s",list[i].name);
			idx[list[i].name]=i;
		}
		while(m--)
		{
			scanf("%s %s %d",a,b,&x);
			list[idx[a]].v-=x, list[idx[b]].v+=x;
		}
		qsort(list,n,sizeof(man),&cmp);
		printf("Case #%d\n",++test);
		For(i,n)
		{
			if(list[i].v<=0) continue;
			j=i+1;
			while(list[i].v>0 && j<n)
			{
				if(list[j].v<0)
				{
				      x=min(list[i].v,abs(list[j].v));
				      printf("%s %s %d\n",list[i].name,list[j].name,x);
				      list[i].v-=x, list[j].v+=x;
				}
				j++;
			}
		}
		printf("\n");
	}
	return 0;
}
