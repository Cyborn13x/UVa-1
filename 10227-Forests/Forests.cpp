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

/*problem id-10227
 *
 *language-C++
 *
 */

using namespace std;

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
	int P;
	int T;
	char a[10];
	bool blank=false;
	set<set<int> > s;
	set<int> st[101];
	scanf("%d",&t);
	getchar();
	getchar();
	while(t--)
	{
	      if(blank) printf("\n");
	      blank=true;
		scanf("%d %d",&P,&T);
		getchar();
		s.clear();
		for(i=1;i<=P;i++) st[i].clear();
		while(gets(a) && sscanf(a,"%d %d",&x,&y)==2) st[x].insert(y);
		for(i=1;i<=P;i++) s.insert(st[i]);
		x=s.size();
            printf("%d\n",x);
	}
	return 0;
}
