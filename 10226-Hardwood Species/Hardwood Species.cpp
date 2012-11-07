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

/*problem id-10226
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i,j,k,l,m,n,t;
	bool fl=0;
	char a[35],c;
	map<string,int> mp;
	map<string,int>::iterator it;;
	scanf("%d",&t);
	getchar();
	getchar();
	while(t--)
	{
		mp.clear();
		n=0;
		while(gets(a) && a[0])
		{
                  n++;
			mp[a]++;
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
			cout << (*it).first << " ";
			printf("%.4lf\n",((*it).second*1.0)/n*100);
		}
		if(t) printf("\n");
	}
	return 0;
}
