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

/*problem id-12015
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
	char a[110];
	vector<string> v[102];
	vector<string>::iterator it;
	scanf("%d\n",&t);
	for(j=0;j<t;j++)
	{
	    for(i=0;i<102;i++) v[i].clear();
		n=10;
		l=-1;
		while(n--)
		{
			scanf("%s %d\n",a,&m);
			v[m].push_back(a);
			l = m>l ? m : l;
		}
		k=v[l].size();
		printf("Case #%d:\n",j+1);
		for(i=0;i<k;i++) cout << v[l][i] << endl;
	}
	return 0;
}
