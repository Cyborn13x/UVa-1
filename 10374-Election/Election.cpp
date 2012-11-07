#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-10374
 *
 *lnaguage-C++
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
	int d[6000];
	bool fl=0;
	char a[1000];
	char b[1000];
	char c;
	map<string,string> mp1;
	map<string,int> mp2;
	map<string,int>::iterator it;
	scanf("%d\n",&t);
	while(t--)
	{
	    memset(d,0,sizeof(d));
	    mp1.clear();
	    mp2.clear();
		if(fl) printf("\n");
		fl=1;
		scanf("%d\n",&m);
		while(m--)
		{
			scanf("%[^\n]",a);
			scanf("%c",&c);
			scanf("%[^\n]",b);
			scanf("%c",&c);
			mp1[a]=b;
		}
		n=-1;
		scanf("%d\n",&m);
		while(m--)
		{
			scanf("%[^\n]",a);
			scanf("%c",&c);
			mp2[a]++;
			if(mp2[a]>n)
			{
			    strcpy(b,a);
			    n=mp2[a];
			}
		}
		for(it=mp2.begin();it!=mp2.end();it++) d[(*it).second]++;
		if(d[n]==1) cout << mp1[b] << endl;
		else printf("tie\n");
	}
	return 0;
}
