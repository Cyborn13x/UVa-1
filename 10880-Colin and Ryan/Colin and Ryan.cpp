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

#define INF 1<<30
#define SZ 100000

/*problem id-10880
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,C,R,blank=0,test=0;
	set<int> ans;
	set<int>::iterator it;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&C,&R);
		n=C-R;
		printf("Case #%d:",++test);
		if(!n) { printf(" 0\n"); continue; }
		ans.clear();
		for(i=1;i*i<=n;i++) if(n%i==0) { ans.insert(i); ans.insert(n/i); }
		for(it=ans.begin();it!=ans.end();it++) if(*it>R) printf(" %d",*it);
		printf("\n");
	}
	return 0;
}
