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

/*problem id-119
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
	bool flag=false;
	char a[100];
	map<string,int> mp;
	vector<string> v;
	while(scanf("%d",&n)!=EOF)
	{
	    if(flag==true) printf("\n");
	    flag=true;
	    v.clear();
	    mp.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			v.push_back(a);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d",a,&l,&t);
			if(l && t) k=l/t;
			else k=0;
			mp[a]-=k*t;
			for(j=0;j<t;j++)
			{
				scanf("%s",a);
				mp[a]+=k;
			}
		}
		l=v.size();
		for(i=0;i<l;i++) cout << v[i] << " " << mp[v[i]] << endl;
	}
	return 0;
}
