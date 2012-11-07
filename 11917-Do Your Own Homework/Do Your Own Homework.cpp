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

/*problem id-11917
 *
 *language-ANSI C
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	char a[30];
	map<string,int> sparrow;
	scanf("%d",&t);
	while(t--)
	{
	      sparrow.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s %d",a,&x);
			sparrow[a]=x;
		}
		scanf("%d %s",&l,a);
		printf("Case %d: ",++test);
		if(!sparrow[a] || sparrow[a]>l+5) printf("Do your own homework!\n");
		else if(sparrow[a]>l) printf("Late\n");
		else printf("Yesss\n");
	}
	return 0;
}
