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

/*problem id-10008
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
	char a[100000];
	vector<int> v;
	vector<int>::iterator itv;
	map<char,int> mp;
	map<int,vector<char> > mp1;
	map<char,int>::iterator it;
    mp.clear();
    mp1.clear();
    v.clear();
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(a);
		for(i=0;a[i]!='\0';i++) if(isalpha(a[i])) mp[toupper(a[i])]++;
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
	    mp1[(*it).second].push_back((*it).first);
	    v.push_back((*it).second);
	}
	sort(v.begin(),v.end());
	itv=unique(v.begin(),v.end());
	v.resize(itv-v.begin());
	n=v.size();
	for(i=n-1;i>=0;i--)
	{
		sort(mp1[v[i]].begin(),mp1[v[i]].end());
		l=mp1[v[i]].size();
		for(j=0;j<l;j++)
		{
			printf("%c %d\n",mp1[v[i]][j],v[i]);
		}
	}
	return 0;
}
